#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[509];
string s;
int vis[509],ans;
void dfs(int x,int y){
    if(x==n){
        if(y>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]!=0)continue;
        vis[i]=x+1;
        int tmp=0;
        if(x-y<c[i]&&s[x]=='1')tmp++;
        dfs(x+1,y+tmp);
        vis[i]=0;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(0,0);
    cout<<ans;
    return 0;
}
