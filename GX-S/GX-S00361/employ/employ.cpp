#include <bits/stdc++.h>
#define MAXN 100
#define int long long
using namespace std;
char nx[MAXN];
char aaa[MAXN];
int diff[MAXN];
char vis[MAXN];
int n,m;
int renshu=0;
int plans=0;
void dfs(int day,int x){
    if(day>n) return;
    vis[x]=1;
    if(diff[x]==1){
        renshu++;
    }
    if(renshu==m){
        plans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(day+1,i);
    }
    if(diff[x]==1) renshu--;
    vis[x]=0;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n>18) return 0;
    scanf("%s",aaa);
    for(int i=0;i<n;i++){
        if(aaa[i]=='0') diff[i+1]=0;
        else diff[i+1]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>nx[i];
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dfs(1,i);
    cout<<plans<<endl;
    return 0;
}
