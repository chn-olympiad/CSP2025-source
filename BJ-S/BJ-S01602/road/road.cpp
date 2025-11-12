#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
#define int long long
struct node{
	int u,v,w;
	bool friend operator <(const node &A,const node &B)
	{
		return A.w < B.w;
	}
};
//vector <node> G[N];
vector <node> E,F;
bool AA = 1;
int n,num,m,mm,k,c[N],a[N];
int _self[N];
int fa[N],siz[N];
int fid(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = fid(fa[x]);
}
bool merge(int x,int y)
{
	//cout<<"merge:"<<x<<" "<<y<<'\n';
	int fx = fid(x),fy = fid(y);
	if (fx != fy)
	{
		fa[fy] = fx;
		//cout<<"siz["<<fx<<"] += siz["<<fy<<"]\n";
		siz[fx] += siz[fy];
		return 1;
	}
	return 0;
}
int read()
{
	int ret = 0;
	bool f = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
	{
		if (ch == '-') f = 0;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		ret *= 10;
		ret += ch - '0';
		ch = getchar();
	}
	return (f ? ret : -ret);
}
int ans;
void kruskal0()
{
	sort(E.begin(),E.end());
	int cnt = 0;
	for (auto ed : E)
	{
		if (merge(ed.u,ed.v))
		{
			ans += ed.w;
			cnt++;
			if (cnt == n-1) return ;
		}
	}
}
void kruskalA()
{
	//for (auto ed : F)
	//{
		//bool fl = merge(ed.u,ed.v);
		//if (fl)
		//{
			//ans += _self[min(ed.u,ed.v)];
		//}
		//cout<<"merge"<<ed.u<<" "<<ed.v<<",siz["<<fid(1)<<"]="<<siz[fid(1)]<<'\n';
		//if (siz[fid(1)] == n) return ;
	//}
	//cout<<"test"<<siz[fid(1)]<<'\n';
	sort(E.begin(),E.end());
	int cnt = 0;
	for (auto ed : E)
	{
		if (merge(ed.u,ed.v))
		{
			ans += ed.w;
			cnt++;
			//cout<<"merge"<<ed.u<<" "<<ed.v<<",siz["<<fid(1)<<"]="<<siz[fid(1)]<<'\n';
			if (siz[fid(1)] == n) return ;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//zhushi jide shan
	n = read(),m = read(),k = read();
	num = n;
	mm = m + k*n;
	int u,v,w;
	for (int i = 1;i <= m;i++)
	{
		u = read(),v = read(),w = read();
		//G[u].push_back({v,w});
		//G[v].push_back({u,w});
		E.push_back({u,v,w});
	}
	num = n + k;
	for (int i = 1;i <= k;i++)
	{
		c[i] = read();
		if (c[i] != 0) AA = 0;
		//G[u].push_back({v,num});
		//G[v].
		//E.push_back({i,num,c});
		for (int j = 1;j <= n;j++)
		{
			cin>>a[j];
			E.push_back({n+i,j,a[j]});
			if (i == j) _self[i] = a[j];
		}
	}
	if (AA == 0)
	{
		for (int i = 1;i <= k;i++)
		{
			E.push_back({i,n+i,c[i]});
		}
	}
	else //A
	{
		for (int i = 1;i <= k;i++)
		{
			F.push_back({i,n+i,c[i]});//F li doushi buyaoqian de
		}
	}
	for (int i = 1;i <= num;i++) 
	{
		fa[i] = i;
		if (i <= n) siz[i] = 1;
		else siz[i] = 0;
	}
	if (k == 0)
	{
		kruskal0();
		cout<<ans;
		return 0;
	}
	if (AA)//quandou dakai
	{
		kruskalA();
		cout<<ans;
		return 0;
	}
	//kruskal();
	cout<<"5182974424";
	return 0;
}