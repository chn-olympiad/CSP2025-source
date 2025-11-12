#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=1e5+5;
int T,n,a[maxn][4];

namespace s1{
    const int maxn=205;
    int dp[maxn][maxn],ans,upp;

    inline void solve(){
        memset(dp,0,sizeof dp);
        upp=n>>1,ans=0;
        int x1,x2,x3;
        for(int i=1;i<=n;i++)
         for(int j=i-1;j>=0;j--)
          for(int k=i-j-1;k>=0;k--){
              dp[j+1][k]=max(dp[j+1][k],dp[j][k]+a[i][1]);
              dp[j][k+1]=max(dp[j][k+1],dp[j][k]+a[i][2]);
              dp[j][k]+=a[i][3];
           }

        for(int i=upp;i>=0;i--)
         for(int j=upp-i;j<=upp;j++)
            ans=max(ans,dp[i][j]);

        printf("%d\n",ans);
    }
}

namespace s2{
    int v[maxn],ans=0;

    inline void solve(){
        for(int i=1;i<=n;i++) v[i]=a[i][1];
        sort(v+1,v+n+1);
        for(int i=n;i>n>>1;i--) ans+=v[i];
        printf("%d",ans);
    }
}
namespace s3{
    int ans=0;
    struct dt{
        int a,b;

        const bool operator<(dt o) const
        { return a+o.b<b+o.a;}
    }d[maxn];

    inline void solve(){
        for(int i=1;i<=n;i++) d[i]={a[i][1],a[i][2]};
        sort(d+1,d+n+1);
        for(int i=n;i>n>>1;i--) ans+=d[i].a;
        for(int i=n>>1;i;i--) ans+=d[i].b;
        printf("%d",ans);
    }
};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    bool flag1=1,flag2=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
            if(a[i][2]) flag1=0;
            if(a[i][3]) flag2=0;
        }

        if(n<=200) s1::solve();
        else if(flag1) s2::solve();
        else if(flag2) s3::solve();
    }

    return 0;
}