#include<bits/stdc++.h>
#define CSP2025 using
#define RP namespace
#define plusplus std
CSP2025 RP plusplus;
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=1e5+5,N2=205;
int n,a[N][3],dp[205][105][105][105],b[N];
//struct node{int i,d;}c[N];
void solve1(){
    memset(dp,0,sizeof dp);
    int p=n>>1,ans=0;
    for(int i=1;i<=n;++i){
        for(int t1=0;t1<=p;++t1){
            for(int t2=0;t2<=p;++t2){
                for(int t3=0;t3<=p;++t3){
                    if(t1)dp[i][t1][t2][t3]=max(dp[i][t1][t2][t3],dp[i-1][t1-1][t2][t3]+a[i][1]);
                    if(t2)dp[i][t1][t2][t3]=max(dp[i][t1][t2][t3],dp[i-1][t1][t2-1][t3]+a[i][2]);
                    if(t3)dp[i][t1][t2][t3]=max(dp[i][t1][t2][t3],dp[i-1][t1][t2][t3-1]+a[i][3]);
                    if(t1+t2+t3==n)ans=max(ans,dp[i][t1][t2][t3]);
                    //cout<<i<<' '<<t1<<' '<<t2<<' '<<t3<<'\n'<<dp[i][t1][t2][t3]<<'\n';
                }
            }
        }
    }cout<<ans<<'\n';
}void solve2(){
    int p=n>>1,ans=0;
    for(int i=1;i<=n;++i)b[i]=a[i][1];
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=p;++i)ans+=b[i];
    cout<<ans<<'\n';
}void solve3(){
    int p=n>>1,ans=0;
    for(int i=1;i<=n;++i)ans+=a[i][1],b[i]=a[i][2]-a[i][1];
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=p;++i)ans+=b[i];
    cout<<ans<<'\n';
}void solve(){
    n=rd();
    for(int i=1;i<=n;++i)a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();
    //solve3();
    if(n<=50)solve1();
    else{
        int s2=0;
        for(int i=1;i<=n;++i)s2+=a[i][2];
        if(s2)solve3();
        else solve2();
    }
}signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=rd();
    while(T--)solve();
}//171720200 206060200
