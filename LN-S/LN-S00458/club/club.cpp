#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
int n,a[maxn],b[maxn],c[maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int flag1=1,flag2=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(b[i]!=0)flag1=0;
            if(c[i]!=0)flag1=flag2=0;
        }
        if(flag1){
            sort(a+1,a+1+n);
            int ans=0;
            for(int i=n;i>n/2;i++){
                ans+=a[i];
            }
            printf("%d\n",ans);
            return 0;
        }
        int f[5][200][200]={};
        f[1][1][0]=a[1],f[1][0][1]=b[1],f[1][0][0]=c[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<=min(i,n/2);j++){
                for(int k=0;k<=min(i-j,n/2);k++){
                    if(i-j-k>n/2)continue;
                    f[i%2][j][k]=f[(i+1)%2][j][k]+c[i];
                    if(j!=0)f[i%2][j][k]=max(f[i%2][j][k],f[(i+1)%2][j-1][k]+a[i]);
                    if(k!=0)f[i%2][j][k]=max(f[i%2][j][k],f[(i+1)%2][j][k-1]+b[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                if(i+j<n/2)continue;
                ans=max(ans,f[0][i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
