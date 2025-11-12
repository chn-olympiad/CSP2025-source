#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int t[1 << 21];
int m, k;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> m >> k;
    for (int i = 0; i < m; i++) cin >> a[i];
    int n = 1, c = 0;
    t[0] = n;
    for (int i = 0; i < m; i++){
        c ^= a[i];
        if (a[i] == k){n++;}
        else if ((t[c^k]) == n){
            n ++;
        }
        t[c] = n;
    }
    cout << n-1 << '\n';
    return 0;
}