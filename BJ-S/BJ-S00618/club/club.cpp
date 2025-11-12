#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100001],f[210][110][110];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
        int ans=0;
        if(n<=200){
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++)
                for(int j=0;j<=i&&j<=n/2;j++)
                    for(int k=0;k<=i-j&&k<=n/2;k++){
                        if(j!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[0][i]);
                        if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[1][i]);
                        if(j+k<i&&i-j-k<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[2][i]);
                    }
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n-i;j++)
                    ans=max(ans,f[n][i][j]);
        }
        else{
            bool f=1;
            for(int i=1;i<=n;i++)if(a[1][i]!=0||a[2][i]!=0)f=0;
            if(f){
                sort(a[0]+1,a[0]+n+1,greater<int>());
                for(int i=1;i<=n/2;i++)ans+=a[0][i];
            }
            else{
                for(int i=1;i<=n;i++)ans+=max({a[0][i],a[1][i],a[2][i]});
            }
        }
        printf("%d\n",ans);
    }
}
