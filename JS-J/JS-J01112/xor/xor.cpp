#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1e2;
int n,k,a[N];
// int f[N],p[25][3],t[N];
int f[N],d[N];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= n;i ++) {
        f[i] = f[i - 1];
        d[i] = a[i] ^ d[i - 1];
        for(int j = i - 1;j >= 0;j --) {
            if(f[j] < f[i]) break;
            if((int)(d[i] ^ d[j]) == k) {
                f[i] = max(f[i],f[j] + 1);
                break;
            }
        }
    }
    cout << f[n] << '\n';
    return 0;
}