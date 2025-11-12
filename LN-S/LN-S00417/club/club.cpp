#include<bits/stdc++.h>
using namespace std;
int t , n ;
struct num{
    int x1 , x2 , x3 ;
} a[220] ;
int f[220][110][110] ;
int c[11] , cnt=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    f[i][j][k]=-2e9;
                }
            }
        }
        f[0][0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(n/2,i);j++){
                for(int k=0;k<=min(n/2,i-j);k++){
                        if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x1);
                        if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].x2);
                        if(l>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].x3);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                ans=max(ans,f[n][i][j]);
            }
        }
        c[++cnt]=ans;
    }
    for(int i=1;i<=cnt;i++){
        printf("%d\n",c[i]);
    }
    return 0;
}
//55fen
