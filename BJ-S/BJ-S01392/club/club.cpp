#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T,n,a[300005],f[205][105][105][105];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while (T--) {
        cin>>n;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n*3;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;i++) {
            for (int j=n/2;j>=0;j--) {
                for (int k=n/2;k>=0;k--) {
                    for (int l=n/2;l>=0;l--) {
                        if (l+1<=n/2) {
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l+1]+a[(i-1)*3+3]);
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
                        }
                        if (k+1<=n/2) {
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k+1][l]+a[(i-1)*3+2]);
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
                        }
                        if (j+1<=n/2) {
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j+1][k][l]+a[(i-1)*3+1]);
                            f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
                        }
                    }
                }
            }
        }
        cout<<f[n][0][0][0]<<" ";
    }

    return 0;
}
