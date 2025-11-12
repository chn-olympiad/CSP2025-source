#include<bits/stdc++.h>
using namespace std;
int n,m,num,k,cnt;
struct node
{
	int u,v;
	long long w;
}e[100050];
struct data
{
	int a1,a2;
	long long w1;
}f[100050],f2[100050];
long long c[100050],ans,a[15][100005];
bool cmp(node q,node p)
{
	return q.w<p.w;
}
bool cmp2(data qp,data pq)
{
	return qp.w1<pq.w1;
}
int dad[100005];
int root(int xx)
{
	if(dad[xx]==xx) return xx;
	return dad[xx]=root(dad[xx]);
}
void init()
{
	for(int i=1;i<=k+n;i++) dad[i]=i;
}
void merge(int qq,int pp)
{
	dad[root(qq)]=root(pp);
}
int b[105];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(root(e[i].u)!=root(e[i].v))
		{
			cnt++;
			f[cnt].a1=e[i].u;
			f[cnt].a2=e[i].v;
			f[cnt].w1=e[i].w;
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
