#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
int a[100010][3];
int f[2][110][110];
int b[100010];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
        }
        if(n<=200){
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++){
                for(int j=0;j<=n/2&&j<=i;j++){
                    for(int k=max((long long)0,i-j-n/2);k<=n/2&&k+j<=i;k++){
                        if(j){
                            f[i&1][j][k]=max(f[i&1][j][k],f[(i&1)^1][j-1][k]+a[i][0]);
                        }
                        if(k){
                            f[i&1][j][k]=max(f[i&1][j][k],f[(i&1)^1][j][k-1]+a[i][1]);
                        }
                        if(i-k-j){
                            f[i&1][j][k]=max(f[i&1][j][k],f[(i&1)^1][j][k]+a[i][2]);
                        }
                    }
                }
            }
            int ans=0;
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2&&k+j<=n;k++){
                    ans=max(ans,f[n&1][j][k]);
                }
            }
            printf("%lld\n",ans);
        }else{
            for(int i=1;i<=n;i++){
                b[i]=a[i][0];
            }
            sort(b+1,b+n+1);
            int ans=0;
            for(int i=n;i>n/2;i--){
                ans+=b[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
