#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5,K=11,N=1e4+15,inf=1e9+7;
struct ed{
    int u,v,w;
}e[M],e2[N];
int tto;
bool operator <(ed a,ed b){
    return a.w<b.w;
}
vector<ed>v[K];
int hd[K];
int cst[K];
int n,m,k;
ll ans;
int fa[N];
int findf(int u){
    if(fa[u]<0)return u;
    return fa[u]=findf(fa[u]);
}
bool meg(int u,int v){
    u=findf(u);
    v=findf(v);
    if(u==v)return 0;
    if(fa[u]<fa[v])swap(u,v);
    fa[v]+=fa[u];
    fa[u]=v;
    return 1;
}
void ck(int stt){
    ll an=0;
    for(int i=1;i<=n+k;i++)fa[i]=-1;
    int pp=0;
    for(int i=1;i<=k;i++){
        hd[i]=1e9;
        if((stt>>(i-1))&1){
            an+=cst[i];
            hd[i]=0;
            pp++;
        }
    }
    hd[0]=1;
    int tot=0,ok;
    ed mn;
    while(tot<pp+n-1){
        mn=e2[hd[0]];
        if(hd[0]>=n)mn=ed{0,0,inf};
        for(int i=1;i<=k;i++){
            if(hd[i]<v[i].size()){
                mn=min(mn,v[i][hd[i]]);
            }
        }
        if(mn.u>n)hd[mn.u-n]++;
        else hd[0]++;
        ok=meg(mn.u,mn.v);
        tot+=ok;
        an+=mn.w*ok;
    }
    ans=min(ans,an);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=-1;
    for(int i=1;i<=m;i++){
        if(meg(e[i].u,e[i].v)){
            e2[++tto]=e[i];
        }
    }
    for(int i=1,w;i<=k;i++){
        cin>>cst[i];
        for(int j=1;j<=n;j++){
            cin>>w;
            v[i].push_back({i+n,j,w});
        }
        sort(v[i].begin(),v[i].end());
    }
    ans=1e18;
    for(int i=0;i<(1<<k);i++){
        ck(i);
    }
    cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
