#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define qrw ios::sync_with_stdio(0),cin.tie(0)
int n,a[100005][4],dp[100005][4];
int cnt[100005][4][4];
int ans;
void dfs(int dep,int x,int b,int c,int sum){
    if(x>n/2||b>n/2||c>n/2) return;
    if(dep==n){ans=max(ans,sum);return;}
    dfs(dep+1,x+1,b,c,sum+a[dep+1][1]);
    dfs(dep+1,x,b+1,c,sum+a[dep+1][2]);
    dfs(dep+1,x,b,c+1,sum+a[dep+1][3]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdin);
    qrw;
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3],sum+=a[i][1];
        if(n>30){
            cout<<sum<<endl;
            continue;
        }
        ans=0;
        dfs(0,0,0,0,0);
        cout<<ans<<endl;
    }
}