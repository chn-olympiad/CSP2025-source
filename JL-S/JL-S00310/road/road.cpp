#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n,m,k;
struct node{
    vector<int>to,tod;
    bool vis=false,can=false;
    int canid,cost;
}c[1001];
int ans=2147483647;
int ca[1001][11];
void dfs(int pos,int sum,int ok){
    if(ok==n){
        //cout<<sum<<endl;
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<c[pos].to.size();i++){
        int nxt=c[pos].to[i],nxtd=c[pos].tod[i];
        if(!c[nxt].vis){
            c[nxt].vis=true;
            dfs(nxt,sum+nxtd,ok+1);
            c[nxt].vis=false;
        }
    }
    if(c[pos].can){
        sum+=c[pos].cost;sum+=ca[pos][pos];
        for(int i=1;i<=n;i++){
            if(!c[i].vis){
                c[i].vis=true;
                dfs(i,sum+ca[i][pos],ok+1);
                c[i].vis=false;
            }
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        c[u].to.push_back(v);
        c[u].tod.push_back(w);
        c[v].to.push_back(u);
        c[v].tod.push_back(w);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i].cost;
        c[i].can=true;
        c[i].canid=i;
        for(int j=1;j<=n;j++)cin>>ca[j][i];
    }
    c[1].vis=true;
    dfs(1,0,1);
    cout<<ans;
    return 0;
}
//16pts
