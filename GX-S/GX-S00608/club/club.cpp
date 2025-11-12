#include<bits/stdc++.h>
using namespace std;
int n,ans,a[400010][3],f[210][120][120],g[100010],gg[100010];
bool b[100010];
inline void solve(){
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    if(n<=0){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    f[i][j][k]=-1<<30;
        }
        f[0][0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i&&j<=n/2;j++){
                for(int k=0;k+j<=i&&k<=n/2;k++){
                    if(f[i][j][k]==(-1<<30)) continue;
                    f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1][0]);
                    f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1][1]);
                    f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1][2]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=(n/2);i++){
            for(int j=0;j+i<=n&&j<=(n/2);j++){
                if((n-i-j)<=(n/2))
                    ans=max(ans,f[n][i][j]);
            }
        }
        printf("%d\n",ans);
        return;
    }
    for(int i=0;i<=n;i++)
        g[i]=gg[i]=-1<<30;
   g[0]=0;
   for(int i=1;i<=n;i++){
        for(int j=0;j<i&&j<=n/2;j++){
            if(g[j]==(-1<<30)) continue;
            gg[j+1]=max(gg[j+1],g[j]+a[i][0]);
            gg[j]=max(gg[j],g[j]+a[i][1]);
        }
        for(int j=0;j<=i&&j<=n/2;j++){
            g[j]=gg[j];
            gg[j]=0;
        }
   }
   printf("%d\n",g[n/2]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
