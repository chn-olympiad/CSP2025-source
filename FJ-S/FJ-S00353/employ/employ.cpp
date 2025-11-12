#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,ans;
char s[maxn];
int c[maxn];
int sq[maxn];
bool vis[maxn];
bool check(){
    int res=0,st=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'||res>=c[sq[i]]) res++;
        else st++;
    }
    //if(st>=m) for(int i=1;i<=n;i++) cout<<sq[i]<<" ";
   // cout<<"\n";
    return st>=m;
}
void dfs(int x){
    if(x==n+1){
        if(check()) ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        sq[x]=i;
        dfs(x+1);
        sq[x]=0;
        vis[i]=0;
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    } 
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    } 
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}