#include<bits/stdc++.h>
using namespace std;	
int n,m,k;
int nn;
struct node
{
	int u;
	int v;
	int w;
}lu[89000005],lu2[80000005];
long long ans=10000000000005;
int c[15];
int lu3[15][10005];
bool b=true;
int fa[10005];
void init()
{
	for(int i=1;i<=n;i++)
	fa[i]=i;
}
int findroot(int root)
{
	if(fa[root]==root)
	return root;
	return fa[root]=findroot(fa[root]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void f(long long sum)
{
	init();
	sort(lu2+1,lu2+m+1,cmp);
	int shu=n;
	int i=0;
	while(shu>1)
	{
		i++;
		int rootu=findroot(lu2[i].u);
		int rootv=findroot(lu2[i].v);
		if(rootu!=rootv)
		{
			sum+=lu2[i].w;
			fa[rootu]=rootv;
			shu--;
		}
	}
	for(int i=1;i<=m;i++)
	{
		lu2[i].u=lu[i].u;
		lu2[i].v=lu[i].v;
		lu2[i].w=lu[i].w;
	}
	ans=min(ans,sum);
}
void dfs(int now,int sum)
{
	if(sum>=ans)
	return ;
	if(now==k+1)
	{
		f(sum);
		return ;
	}
	n++;
	for(int i=1;i<=nn;i++)
	{
		lu[++m].u=i;
		lu[m].v=n;
		lu[m].w=lu3[now][i];
		lu2[m].u=i;
		lu2[m].v=n;
		lu2[m].w=lu3[now][i];
	}
	dfs(now+1,sum+c[now]);		
	n--;
	m-=nn;	
	if(c[now]!=0)
		dfs(now+1,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=m;i++)
	{
		cin>>lu[i].u>>lu[i].v>>lu[i].w;
		lu2[i].u=lu[i].u;
		lu2[i].v=lu[i].v;
		lu2[i].w=lu[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>lu3[i][j];
	}
	dfs(1,0);
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
