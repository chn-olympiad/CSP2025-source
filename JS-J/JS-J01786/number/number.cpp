#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;
    long long b[10] = {};
    for (int i = 0; i < a.size(); i++){
        if ('0' <= a[i] && '9' >= a[i]){
            b[a[i] - '0'] ++;
        }
    }
    for (int i = 9; i >= 0; i--){
        for (int j = 0; j < b[i]; j++){
            cout << i;
        }
    }
    return 0;
}
