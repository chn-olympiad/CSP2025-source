#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long a,b,c;
};
long long n,m,k;
long long ans = 0x3f3f3f3f;
long long fa[1000005];
long long b[15][100005];
long long val[15];//城市化费用 
long long p[15];//选择 
long long u[1000005],v[1000005],w[1000005];
vector<Node> e;
long long find(long long x)
{
	if (fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool cmp(Node x,Node y)
{
	return x.c < y.c;
}
void kruaskle(long long t)
{
	long long cnt = 0;
	long long aans = 0;
	for (long long i = 1;i <= k;i++)
	{
		if (p[i])
		{
			aans += val[i];
		}
	}
	sort(e.begin(),e.end(),cmp); 
	memset(fa,0,sizeof(fa));
	for (long long i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	for (long long i = 0;i < e.size();i++)
	{
		if (find(e[i].a) == find(e[i].b))
		{
			continue;
		}
		fa[find(e[i].a)] = find(e[i].b);
		cnt++;
		aans += e[i].c;
		if (cnt == t - 1)
		{
			break;
		}
	}
	ans = min(ans,aans);
	return ;
}
void dfs(long long xxx)
{
	if (xxx == k + 1)
	{
		long long cccnt = 0;
		e.clear();
		for (long long i = 1;i <= n;i++)
		{
			e.push_back((Node){u[i],v[i],w[i]});
		}
		for (long long i = 1;i <= k;i++)
		{
			if (p[i])
			{
				for (long long j = 1;j <= n;j++)
				{
					e.push_back((Node){n + i,j,b[i][j]});
				}
				cccnt++;
			}
		}
		kruaskle(n + cccnt);
		return ;
	}
	p[xxx] = 1;
	dfs(xxx + 1);
	p[xxx] = 0;
	dfs(xxx + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (long long i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for (long long i = 1;i <= k;i++)
	{
		cin >> val[i];
		for (long long j = 1;j <= n;j++)
		{
			cin >> b[i][j];
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
