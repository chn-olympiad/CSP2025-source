#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+15;
struct node{
    int a,b,c,d,t;
};
int _,n,ans;
int dp[205][205][205];
node a[MAXN];
inline void solve(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        ans+=a[i].a;
    }
    if(n<=200){
        ans=0;
        memset(dp,0xcf,sizeof(dp));
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;j+k<=i;k++){
                    dp[i][j][k]=dp[i-1][j][k]+a[i].c;
                    if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].a);
                    if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].b);
                }
            }
        }
        for(int i=0;i<=n>>1;i++) for(int j=0;j<=n>>1;j++) if(n-i-j<=n>>1) ans=max(dp[n][i][j],ans);
        cout<<ans<<'\n';
        return;
    }
    sort(a+1,a+1+n,[](const node &a,const node &b){return a.b-a.a>b.b-b.a;});
    for(int i=1;i<=n>>1;i++) ans+=a[i].b-a[i].a;
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>_;
    while(_--) solve();
    return 0;
}
