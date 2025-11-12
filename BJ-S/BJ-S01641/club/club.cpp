#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int max(int a,int b){
    return a>b?a:b;
}
int T;
int n,a[N][4];
int chk(){
    bool a0=true,b0=true,c0=true;
    for(int i=1;i<=n;i++)
        if(a[i][1]!=0){
            a0=false;
            break;
        }
    for(int i=1;i<=n;i++)
        if(a[i][2]!=0){
            b0=false;
            break;
        }
    for(int i=1;i<=n;i++)
        if(a[i][3]!=0){
            c0=false;
            break;
        }
    if(a0==1&&b0==1&&c0==1) return 0;
    if(a0==0&&b0==1&&c0==1) return 1;
    if(a0==1&&b0==0&&c0==1) return 2;
    if(a0==1&&b0==1&&c0==0) return 3;
    if(a0==1&&b0==0&&c0==0) return 4;
    if(a0==0&&b0==1&&c0==0) return 5;
    if(a0==0&&b0==0&&c0==1) return 6;
    return 7;
}
namespace solve{
    int dp[101][101][101][3];
    void work(){
        memset(dp,0,sizeof dp);
        for(int j1=1;j1<=n>>1;j1++)
            for(int j2=1;j2<=n>>1;j2++)
                for(int j3=1;j3<=n>>1;j3++)
                    for(int i=n;i>=1;i--){
                        dp[j1][j2][j3][1]=dp[j1-1][j2][j3][1]+a[i][1];
                        dp[j1][j2][j3][1]=max(dp[j1][j2][j3][1],max(dp[j1-1][j2][j3][2],dp[j1-1][j2][j3][3])+a[i][1]);
                        dp[j1][j2][j3][2]=dp[j1][j2-1][j3][2]+a[i][2];
                        dp[j1][j2][j3][2]=max(dp[j1][j2-1][j3][2],max(dp[j1][j2-1][j3][1],dp[j1][j2-1][j3][3])+a[i][2]);
                        dp[j1][j2][j3][3]=dp[j1][j2][j3-1][3]+a[i][3];
                        dp[j1][j2][j3][3]=max(dp[j1][j2][j3][3],max(dp[j1][j2][j3-1][2],dp[j1][j2][j3-1][3])+a[i][3]);
                    }
        int ans=-1;
        ans=max(dp[n>>1][n>>1][n>>1][1],max(dp[n>>1][n>>1][n>>1][2],dp[n>>1][n>>1][n>>1][3]));
        printf("%d\n",ans);
        return;
    }
}
namespace solve1{
    int did[N];
    int dfs(int now,int typ,int s1,int s2,int s3){
        if(s1>(n>>1)||s2>(n>>1)||s3>(n>>1)){
            return 0;
        }
        did[now]=typ;
        if(now==n){
            int ans=0;
            for(int i=1;i<=n;i++) ans+=a[i][did[i]];
            return ans;
        }
        int ans=-1;
        for(int i=1;i<=3;i++) ans=max(ans,dfs(now+1,i,s1+((i==1)?1:0),s2+((i==2)?1:0),s3+((i==3)?1:0)));
        return ans;
    }
    void work(){
        memset(did,0,sizeof did);
        int res=-1;
        for(int i=1;i<=3;i++){
            res=max(res,dfs(1,i,(i==1)?1:0,(i==2)?1:0,(i==3)?1:0));
        }
        printf("%d\n",res);
        return;
    }
}
namespace solve2{
    int b[N];
    void work1(){
        for(int i=1;i<=n;i++) b[i]=a[i][1];
        sort(b+1,b+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n>>1;i++) ans+=b[i];
        printf("%d\n",ans);
        return;
    }
    void work2(){
        for(int i=1;i<=n;i++) b[i]=a[i][2];
        sort(b+1,b+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n>>1;i++) ans+=b[i];
        printf("%d\n",ans);
        return;
    }
    void work3(){
        for(int i=1;i<=n;i++) b[i]=a[i][3];
        sort(b+1,b+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n>>1;i++) ans+=b[i];
        printf("%d\n",ans);
        return;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        int c=chk();
        if(c==0) printf("0\n");
        else if(c==1) solve2::work1();
        else if(c==2) solve2::work2();
        else if(c==3) solve2::work3();
        else if(n<=10) solve1::work();
        else if(n<=200) solve::work();
    }
    return 0;
}