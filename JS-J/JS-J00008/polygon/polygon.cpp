#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n;
int a[5010];
bool vis[5010];
int ans=0;
void dfs(int s,int mx,int cnt,int x){
    if(cnt>=3){
        if(s>mx*2){
            ans++;
            ans%=MOD;
        }
    }
    for(int i=x;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(s+a[i],max(mx,a[i]),cnt+1,i+1);
            vis[i]=false;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }

    if(mx<=1){
        int ret=1;
        for(int i=0;i<n;i++){
            ret=(ret*2);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=i;
        }
        cout<<(ret-ans-1)%MOD;
        return 0;
    }

    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
