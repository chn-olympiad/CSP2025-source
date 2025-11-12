#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll len=5e3+10,mod=998244353;
ll n,res;
ll a[len];
ll dp[len][len];
bool vis[len];
void dfs(ll stp){
    if(stp==n+1){
        ll mx=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                mx=max(mx,a[i]);
                cnt+=a[i];
            }
        }
        if(mx==cnt&&mx==0)return ;
        if(mx*2<cnt){
            res++;
        }
        return ;
    }
    dfs(stp+1);
    vis[stp]=1;
    dfs(stp+1);
    vis[stp]=0;
    return ;
}
bool checkA(){
    for(int i=1;i<=n;i++){
        if(a[i]!=1)return false;
    }
    return true;
}
int main(){
    freopen("polygon.in","r",stdin);//100+100+60+60 too weak for csp TAT
    freopen("polygon.out","w",stdout);//may i be lucky again?
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=20){//40
        dfs(1);
        cout<<res%mod;
        return 0;
    }
    if(checkA()){//20
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            dp[i][i]=1;
            for(int j=1;j<i;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        for(int i=3;i<=n;i++){
            res=(res+dp[n][i])%mod;
        }
        cout<<res;
        return 0;
    }
    for(int i=3;i<=n;i++){//find the greatest
        for(int j=3;j<=i;j++){// the second greatest
            //i'm not sure what to do next.just for the last 15min i'll try 11;30
            // give up...
            // i have actually a thought if we find those combinations that we can't get a polygon
            // then we can use the sum to minus it\\ ill try now.
            // never mind, i can't write that one too.
            //11:45 and i'm doomed
        }
    }
    cout<<res;
    return 0;
}
