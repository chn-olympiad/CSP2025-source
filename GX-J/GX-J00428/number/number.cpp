#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;

    int arr[s.size()];
    int len = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] - '0' <= 9 && s[i] - '0' >= 0) {
            arr[len] = s[i] - '0';
            len++;
        }
    }

    sort(arr, arr + len);

    for(int i = len - 1; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
