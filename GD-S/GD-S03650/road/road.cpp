#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
struct edge{
    int x,y,v,next,id;
}e[4000010];
int t[1000010];
int head[4000010],cnt=0;
int ans=0;
int fa[1000010];
bool v[1000010];

void insert(int x,int y,int v){
    e[++cnt]={x,y,v,head[x],cnt};
    head[x]=cnt;
}

int findfa(int x){
    if(fa[x]==x)return x;
    fa[x]=findfa(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    fa[findfa(x)]=findfa(y);
}

bool cmp(edge x,edge y){
    if(x.x<=k)x.v+=t[x.x];
    if(x.y<=k)x.v+=t[x.y];
    if(y.x<=k)y.v+=t[y.x];
    if(y.y<=k)y.v+=t[y.y];
    return x.v<y.v;
}

void kruskal(){
    int tot=0;ans=0;
    sort(e+1,e+cnt,cmp);
    for(int i=1;i<cnt;i++){
        int x=e[i].x,y=e[i].y,d=e[i].v;
        if(findfa(x)==findfa(y))continue;
        merge(x,y);
        ans+=d;
        tot++;
        if(!v[x]&&e[i].id>2*m){ans+=t[x];v[x]=1;}
        if(!v[y]&&e[i].id>2*m){ans+=t[y];v[y]=1;}
        if(tot==n-1){
            break;
        }
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(head,-1,sizeof(head));
    memset(t,0,sizeof(t));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        insert(x,y,v);
        insert(y,x,v);
    }
    for(int i=1;i<=k;i++){
        cin>>t[i];
        for(int j=1;j<=n;j++){
            int v1;
            cin>>v1;
            if(j==t[i])continue;
            if(j<=k)v1+=t[j];
            insert(i,j,v1+t[i]);
            insert(j,i,v1+t[i]);
        }
    }
    memset(v,1,sizeof(v));
    for(int i=1;i<=k;i++)v[i]=0;
    kruskal();
    cout<<ans;
    return 0;
}