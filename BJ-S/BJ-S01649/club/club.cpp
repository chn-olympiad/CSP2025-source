#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
using namespace std;
const int N=205;
int n,a[N],b[N],c[N],dp[N][N][N];
int ans=0;
void dfs(int d,int sum,int cnta,int cntb,int cntc){
    if(d>n){
        if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
            ans=max(ans,sum);
        }
        return;
    }
    dfs(d+1,sum+a[d],cnta+1,cntb,cntc);
    dfs(d+1,sum+b[d],cnta,cntb+1,cntc);
    dfs(d+1,sum+c[d],cnta,cntb,cntc+1);
}
void solve(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    if(n<=10){
        ans=0;
    dfs(1,0,0,0,0);
    cout<<ans<<endl;
    return;
    }else{
 for(int i=1;i<=n;i++){
        for(int j=1;j<=n/2;j++){
            if(j>i) break;
            dp[i][0][j]=dp[i-1][0][j-1]+b[i];
            dp[i][j][0]=dp[i-1][j-1][0]+a[i];
        }
        dp[i][0][0]=dp[i-1][0][0]+c[i];
        for(int j=1;j<=n/2;j++){
            for(int k=1;k<=n/2;k++){
                if(j+k<n/2) continue;
                dp[i][j][k]=max(max(dp[i-1][j][k]+c[i],dp[i-1][j-1][k]+a[i]),dp[i-1][j][k-1]+b[i]);
            }
        }
        // for(int j=0;j<=n/2;j++){
        //     for(int k=0;k<=n/2;k++){
        //         cout<<dp[i][j][k]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    int ans=0;
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            if(n-i-j<=n/2) ans=max(ans,dp[n][i][j]);
        }
    }
    cout<<ans<<endl;
    }
    
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;while(T--)solve();
    return 0;
}