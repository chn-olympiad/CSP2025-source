#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int n,k;
int f[N][N];

int main() {
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" ,stdout);
    cin>>n>>k;
    memset(f , -1 , sizeof f);
    int a[n + 1];
    int ans = 0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        f[i][i] = a[i];
    }
    for (int k=2;k<=n;k++) {
        for (int i=1;i<=n-k+1;i++) {
            int j = i + k - 1;
            if (f[i][j - 1] != -1) f[i][j] = f[i][j - 1] ^ a[j];
        }
    }
    int p = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (f[i][j] == k) {
                if (j > p) {
                    p = j;
                    ans ++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
