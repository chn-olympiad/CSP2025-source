#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2e6 + 5;
int a[N], f[N], lst[M], s[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k; cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i], s[i] = s[i-1] ^ a[i];
    for(int i = 1;i <= n;i++) {
        f[i] = f[i-1];
        if(s[i] == k || lst[s[i] ^ k] != 0) 
            f[i] = max(f[i], f[lst[s[i] ^ k]] + 1);
        lst[s[i]] = i;
    } cout << *max_element(f+1, f+n+1) << endl;
    return 0;
}