#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct Line
{
	long long u,v,w;
	
	Line(int a,int b,int c):
		u(a),v(b),w(c)
		{
			
		}
};
vector<int> fa;
int f(int x)
{
	if(fa[x] != fa[fa[x]])fa[x] = f(fa[x]);
	return fa[x];
}
struct Compera
{
	bool operator()(const Line& a,const Line& b)
	{
		return a.w > b.w;
	}
};
priority_queue<Line,vector<Line>,Compera> l;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	fa.resize(n + 1,0);
	for(int i = 1;i <= n;++ i)fa[i] = i;
	for(int i = 1;i <= m;++ i)
	{
		long long u,v,w;
		cin >> u >> v >> w;
		l.push(Line(u,v,w));
	}
	for(int i = 1;i <= k;++ i)
	{
		int x;
		cin >> x;
		vector<long long> a;
		a.resize(n + 1,0);
		for(int i = 1;i <= n;++ i)
		{
			cin >> a[i];
		}
	}
	while(!l.empty())
	{
		Line x = l.top();
		l.pop();
		if(f(x.u) == f(x.v))continue;
		ans += x.w;
		fa[f(x.u)] = f(x.v);
		bool flag = true;
		for(int i = 2;i <= n;++ i)
		{
			if(f(i) != f(1))
			{
				flag = false;
				break;
			}
		 } 
		 if(flag)
		 {
		 	break;
		 }
	}
	cout << ans;
	return 0;
}

