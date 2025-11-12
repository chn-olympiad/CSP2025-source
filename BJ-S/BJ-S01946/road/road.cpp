#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int w,v;
    node(int _w,int _v){
        w=_w;
        v=_v;
    }
};
int n,m,cnt=1e16,k,vis[10009],vp=1;
vector<node> p[10009];
void dfs(int x,int s){
    //cout<<vp<<' ';
    vp++;vis[x]=1;
    if(vp==n){
        cnt=min(cnt,s);
        //cout<<cnt;
        vp--;
        return;
    }//cout<<p[1].size();
    for(int i=0;i<p[x].size();i++){
        int tx=p[x][i].v;
        if(!vis[tx]){
            dfs(tx,s+p[x][i].w);
        }
    }
    vp--;vis[x]=0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        p[u].push_back(node(w,v));
        p[v].push_back(node(w,u));
    }
    dfs(1,0);
    cout<<cnt;
    return 0;
}
