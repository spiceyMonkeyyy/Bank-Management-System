#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 500;

struct BankAccount {
    int accountNumber;
    string holderName;
    double balance;
};

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Account limit reached. Cannot create more accounts.\n";
        return;
    }
    
    BankAccount newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cin.ignore();  
    cout << "Enter holder name: ";
    getline(cin, newAccount.holderName);
    newAccount.balance = 0.0;
    
    accounts[accountCount++] = newAccount;
    cout << "Account created successfully!\n";
}

void deposit() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "Amount deposited successfully! New balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

void withdraw() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > accounts[i].balance) {
                cout << "Insufficient balance.\n";
            } else {
                accounts[i].balance -= amount;
                cout << "Amount withdrawn successfully! New balance: " << accounts[i].balance << endl;
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void checkBalance() {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

void displayMenu() {
    cout << "\nBank Account Management System\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
