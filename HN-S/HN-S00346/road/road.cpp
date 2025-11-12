#include<bits/stdc++.h>
#define N 10005
#define M 1000005
using namespace std;
int n,m,k,c[N];
int a[12][N];
struct node2
{
    int v,w;
};
vector<node2> g[N];
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
int fa[M];
void init()
{
    for(int i=1;i<=n;++i) fa[i]=i;
}
struct node
{
    int u,v,w;
}l[N];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void Union(int x,int y)
{
    int a=find(x),b=find(y);
    if(a!=b) fa[a]=b;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int ans=0,cnt=1,tot=0;
    n=read(),m=read(),k=read();
    int u,v,w;
    for(int i=1;i<=m;++i){
        u=read(),v=read(),w=read();
        l[i].u=u,l[i].v=v,l[i].w=w;
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j){
            a[i][j]=read();
        }
    }
    init();
    sort(l+1,l+m+1,cmp);
    for(int i=1;i<=m;++i){
        if(find(l[i].u)!=find(l[i].v)){
            Union(l[i].u,l[i].v);
            ans+=l[i].w;
            ++cnt;
        }
        if(cnt==n) break;
    }
    cout<<ans<<"\n"; 
    return 0;
}