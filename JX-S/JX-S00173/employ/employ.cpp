#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=502;
int n,m,ans=0,c[N];
string s;
bool vis[N];
void dfs(int p,int cnt){
    if(n-p+cnt<m) return ; 
    if(p>=n){
        if(cnt>=m) ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(p-cnt>=c[i]||s[p]=='0') dfs(p+1,cnt);
        else dfs(p+1,cnt+1);
        vis[i]=0;
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(0,0);
    cout<<ans;
    return 0;
}