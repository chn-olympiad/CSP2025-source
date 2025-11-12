#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int T;
int n;
int a[MAXN][4];
int f[103][103][103];
int main(){
    // freopen("club4.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        f[0][0][0]=0; int ans=0;
        for (int i=0;i<=n/2;i++){
            for (int j=0;j<=n/2;j++){
                for (int k=0;k<=n/2;k++){
                    if (i==0&&j==0&&k==0) continue;
                    if (i+j+k>n) continue;
                    f[i][j][k]=0;
                    if (i!=0){
                        f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i+j+k][1]);
                    }
                    if (j!=0){
                        f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[i+j+k][2]);
                    }
                    if (k!=0){
                        f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[i+j+k][3]);
                    }
                    if (i+j+k==n) ans=max(ans,f[i][j][k]);
                }
            }
        }
        cout<<ans<<'\n';
    }    
    return 0;
}