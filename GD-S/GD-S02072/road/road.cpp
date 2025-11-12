#include <bits/stdc++.h>
using namespace std;
int p[10001];
int find(int x)
{
	if(x==p[x])
	{
		return x;
	}
	return p[x]=find(p[x]);
}
struct str
{
	int u, v;
	long long w;
}s[1000001];
struct str2
{
	int v;
	long long w;
	bool operator > (const str2 &o) const
	{
		return w>o.w;
	}
};
long long d[10015], c[15];
bool b[10015];
vector<str2> v[10015];
priority_queue<str2, vector<str2>, greater<str2> >pq;
bool cmp(str x, str y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i<=n; i++)
	{
		p[i]=i;
	}
	for(int i = 1; i<=m; i++)
	{
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	for(int i = 1; i<=k; i++)
	{
		cin >> c[i];
		for(int j = 1; j<=n; j++)
		{
			long long x;
			cin >> x;
			v[j].push_back({i+n, x});
			v[i+n].push_back({j, x});
		}
	}
	sort(s+1, s+m+1, cmp);
	int lian=n;
	long long ans = 0;
	for(int i = 1; i<=m; i++)
	{
		if(find(s[i].u)!=find(s[i].v))
		{
			v[s[i].u].push_back({s[i].v, s[i].w});
			v[s[i].v].push_back({s[i].u, s[i].w});
			s[i].u=find(s[i].u), s[i].v=find(s[i].v);
			p[s[i].v]=s[i].u;
			lian--;
			ans+=s[i].w;
			if(lian==1)
			{
				break;
			}
		}
	}
	for(int flag = 1; flag<(1 << k); flag++)
	{
		long long now = 0;
		for(int i = 1; i<=k; i++)
		{
			if((1 << (i-1))&flag)
			{
				now+=c[i];
			}
		}
		for(int i = 2; i<=n+k; i++)
		{
			d[i]=1e9+1;
			b[i]=0;
		}
		pq.push({1, 0});
		while(pq.size())
		{
			int id = pq.top().v;
			long long w = pq.top().w;
			pq.pop();
			if(w>d[id])
			{
				continue;
			}
			b[id]=1;
			now+=w;
			for(int i = 0; i<v[id].size(); i++)
			{
				if(b[v[id][i].v])
				{
					continue;
				}
				if(v[id][i].v>n && (((1 << (v[id][i].v-n-1))&flag)==0))
				{
					continue;
				}
				if(v[id][i].w<d[v[id][i].v])
				{
					d[v[id][i].v]=v[id][i].w;
					pq.push({v[id][i].v, d[v[id][i].v]});
				}
			}
		}
		ans=min(ans, now);
	}
	cout << ans << endl;
	return 0;
}
