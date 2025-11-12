#include<bits/stdc++.h>
using namespace std;
long long n,m,k,epool,ans,fa[20011],npool=12000,countt;
struct EDGE{
    long long u,v,w;
    EDGE *next;
}es[10000001];
struct NODE{
    EDGE *fir;
}ns[20011];
void addedges(long long u,long long v,long long w){
    es[++epool].u=u;
    es[epool].v=v;
    es[epool].w=w;
    es[epool].next=ns[u].fir;
    ns[u].fir=&es[epool];
}
long long findx(long long x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=findx(fa[x]);
}
void join(long long x,long long y){
    long long xx=findx(x);
    long long yy=findx(y);
    if(xx==yy){
        return;
    }
    fa[x]=y;
}
bool cmp(EDGE e1,EDGE e2){
    return e1.w<e2.w;
}
long long dfs(long long u){
    for(int i=1;i<=m;i++){
        long long yu1=findx(es[i].u);
        long long yu2=findx(es[i].v);
        if(yu1==yu2){
            continue;
        }else{
            join(yu1,yu2);
            ans+=es[i].w;
            countt++;
            if(countt>=n-1){
                return ans;
            }
        }

    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    long long u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        addedges(u,v,w);
    }
    long long c;
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>w;
        }
    }
    sort(es+1,es+m+1,cmp);
    cout<<dfs(1)<<endl;
    return 0;
}

