#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
int n,k;
int a[N];
int ans=0;
int mav=1;
int dp[N][N];
void dfs(int x,int y,int cnt){
    if(x>n||y>n){
        ans=max(cnt,ans);
        return;
    }
    if(dp[x][y]==k){
        int afte=max(x,y);
        dfs(afte+1,afte+1,cnt++);
    }
    dfs(x,y+1,cnt);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[0][i]=a[i];
        dp[i][0]=a[i];
        dp[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp[i][j]==-1)    dp[i][j]=(dp[0][j]^dp[i][j-1]);
        }
    }
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
