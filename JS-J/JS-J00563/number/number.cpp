#include <bits/stdc++.h>
using namespace std;

int arr[10];
string num;

void output() {
    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < arr[i]; j++)
            cout << i;
    return ;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> num;

    for (char c : num)
        if ('0' <= c && c <= '9') arr[c - '0']++;

    output();
    return 0;
}
