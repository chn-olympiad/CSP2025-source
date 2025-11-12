/*
1.开freopen
2.for循环
3.倒序遍历i--
4.开ll
5.数组溢出
6.初始化
7.删debug语句
8.n*m数组遍历
//*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,fir[10005],num=0;
struct edge
{
	int u,v,nxt;
	ll w;
}e[2000005];
void add(int u,int v,ll w)
{
	e[++num].nxt=fir[u];
	fir[u]=num;
	
	e[num].u=u,e[num].v=v,e[num].w=w;
}
int f[10005];
int findf(int i)
{
	if(f[i]==i)return i;
	return f[i]=findf(f[i]);
}
void join(int x,int y)
{
	f[x]=y;
}
bool same(int x,int y)
{
	return findf(x)==findf(y);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
ll mintree()
{
	ll ans=0;
	sort(e+1,e+num+1,cmp);
	for(int i=1,j=1;i<=num&&j<n;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(same(u,v))continue;
		join(u,v);
		ans+=e[i].w;
		j++;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int fys;//自身的费用
		int a[10005];
		cin>>fys;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				add(i,j,ll(fys)+a[i]+a[j]);
	}
	
	cout<<mintree();
	return 0;
}

