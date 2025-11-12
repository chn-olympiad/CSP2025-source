#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,ans;
int c[510],vis[510];
string nd;
void dfs(int u,int step,int sum,int rn){
    vis[u]=1;
    if(rn<c[u]&&nd[step-1]=='1') sum++;
    if(nd[step-1]=='0') rn++;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,step+1,sum,rn);
        }
    }
    if(step==n){
        if(sum>=m) ans++;
    }
    vis[u]=0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>nd;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) dfs(i,1,0,0);
    cout<<ans;
    return 0;
}
