#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005],cnt=0,n;
ll vis[10005];
void dfs(ll x,ll sum,ll maxn,ll cnts){
    if(sum>maxn*2 && cnts>=3){
        cnt++;
        cnt%=998244353;
    }
    for(int i=x+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,sum+a[i],max(maxn,a[i]),cnts+1);
            vis[i]=0;
        }
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        vis[i]=1;
        dfs(i,a[i],a[i],1);
        vis[i]=0;
    }
    cout<<cnt;
    return 0;
}
