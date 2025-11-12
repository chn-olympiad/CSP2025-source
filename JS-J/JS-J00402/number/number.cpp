#include <bits/stdc++.h>
using namespace std;
const int SIZE  = 1e6;
string s;
int a[SIZE + 5], n;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
            a[n] = s[i] - '0';
            n++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[j] >= a[i]){
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;
    return 0;
}