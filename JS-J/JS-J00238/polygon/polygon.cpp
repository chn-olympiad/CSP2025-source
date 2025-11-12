#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
int a[5005],vis[5005][5005],ans=0,n,f[5005];
LL sum=0;
void dfs(int dep,int st,int k,LL ans){
    if(dep>k){
        int mx=-1e9;
        for(int i=1;i<dep;i++) mx=max(mx,f[i]);
        if(ans>mx*2){
            sum++;
            sum%=998244353;
        }
        return ;
    }
    else{
        for(int i=st;i<=n;i++){
            if(!vis[dep][i]){
                vis[dep][i]=1;
                f[dep]=a[i];
                dfs(dep+1,i+1,k,ans+a[i]);
                vis[dep][i]=0;
            }
        }
        return ;
    }
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    for(int i=2;i<=n;i++){
        dfs(1,1,i,0);
    }
    cout<<sum;
    return 0;
}