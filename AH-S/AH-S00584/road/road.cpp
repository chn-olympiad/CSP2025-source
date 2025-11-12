#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1e18;
int n,m,k;
int fa[10005];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
int c[15];
int a[15][10005];
struct edge{
    int u,v,w;
}e[1000005];
bool operator < (const edge x,const edge y){
    return x.w>y.w;
}
priority_queue<edge>q;
ll work(int st){
    ll res=0;
    int t=0;
    priority_queue<edge>s=q;
    if(st==0)while(!q.empty())q.pop();
    for(int i=0;i<k;i++){
        if((st>>i)&1){
            t++;
            for(int j=1;j<=n;j++){
                s.push({t+n,j,a[i+1][j]});//here
            }
            res+=c[i+1];
        }
        if(res>ans)return 1e18;
    }
    for(int i=1;i<=n+t;i++)fa[i]=i;
    int tot=0;
    while(tot<n+t-1){
        edge x=s.top();
        s.pop();
        int u=x.u,v=x.v;
        int fu=find(u),fv=find(v);
        if(fu==fv)continue;
        //cout<<x.w<<endl;
        fa[fu]=fv;
        tot++;
        res+=x.w;
        if(st==0)q.push(x);
        if(res>ans)return 1e18;
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool f=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        q.push(e[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i])f=1;
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    int st=0;
    if(!f)st=(1<<k)-1;
    for(int i=st;i<(1<<k);i++)ans=min(ans,work(i));
    printf("%lld\n",ans);
}
