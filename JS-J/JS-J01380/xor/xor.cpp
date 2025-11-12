#include<bits/stdc++.h>
using namespace std;

int a[1005], f[1005][1005], s[1005];
int n, k;

int getsum(int l, int r) {
    if (l == 1) return s[r];
    else return s[r] ^ s[l-1];
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i], f[i][i] = int(a[i]==k);
    s[1] = a[1];
    for (int i=2; i<=n; i++) s[i] = a[i] ^ s[i-1];
    for (int len=2; len<=n; len++) {
        for (int l=1; l+len-1<=n; l++) {
            int r = l + len - 1;
            for (int k=l; k<r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k+1][r]);
            if ((!f[l][r]) && (getsum(l, r) == k)) f[l][r] = 1;
        }
    }
    cout << f[1][n];
    return 0;
}
