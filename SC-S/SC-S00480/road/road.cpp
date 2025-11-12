#include<bits/stdc++.h>
using namespace std;
struct DSU
{
	vector<int> f;
	void f0(int n)
	{
		f.resize(n);
		for(int x=0;x<n;x++)
			f[x]=x;
	}
	int fa(int x)
	{
		while(f[x]!=x)
		{
			x=f[x];
			f[x]=f[f[x]]=f[f[f[x]]];
		}
		return x;
	}
	bool same(int x,int y)
	{
		return fa(x)==fa(y);
	}
	void merge(int x,int y)
	{
		if(fa(x)==fa(y))
			return ;
		f[y]=fa(x);
		return ;
	}
};
int n,m,z=0;
vector<vector<int>> a,b;
bool cmp(vector<int> &a,vector<int> &b)
{
	return a[2]<b[2];
}
int klr(int n)
{
	DSU dsu;
	dsu.f0(n);
	vector<vector<int>> pa;
	for(int x=0;x<n;x++)
		for(int y=0;y<(int)a[x].size();y++)
			pa.push_back({x,a[x][y],b[x][y]});
	sort(pa.begin(),pa.end(),cmp);
	for(int x=0;x<(int)pa.size();x++)
	{
		if(!dsu.same(a[x][0],a[x][1]))
		{
			dsu.merge(a[x][0],a[x][1]);
			z+=a[x][2];
		}
	}
	return z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	a.resize(n+k+3);
	b.resize(n+k+3);
	for(int x=0;x<m;x++)
	{
		int ax,ay,az; cin>>ax>>ay>>az;
		a[ax].push_back(ay);
		b[ax].push_back(az);
		a[ay].push_back(ax);
		b[ay].push_back(az);
	}
	for(int x=1;x<=k;x++)
	{
		int ax; cin>>ax;
		for(int y=0;y<n;x++)
		{
			cin>>ax;
			a[n+x-1].push_back(y);
			b[n+x-1].push_back(ax);
			a[y].push_back(n+x-1);
			b[y].push_back(ax);
		}
	}
	cout<<klr(n+k+3);
	return 0;
}