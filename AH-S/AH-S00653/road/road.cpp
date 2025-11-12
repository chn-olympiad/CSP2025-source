#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int a[15][10005],c[15];
int fa[10005];
struct edge
{
    int u,v,val;
}e[1000005];
bool cmp(edge a1,edge a2)
{
    return a1.val<a2.val;
}
int find1(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find1(fa[x]);
}
void join(int x,int y)
{
    int f1=find1(x),f2=find1(y);
    if(f1!=f2) fa[f1]=f2;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=0;
	int u,v,w;
	for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e[i]=(edge){u,v,w};
    }
	for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find1(e[i].u)==find1(e[i].v)) continue;
        ans+=e[i].val;
        join(e[i].u,e[i].v);
        n--;
        if(n==1) break;
    }
    cout<<ans;
	return 0;
}
