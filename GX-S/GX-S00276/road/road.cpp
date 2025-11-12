#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+99 , M = 1e7+99;

struct edge
{
	int u , v , w;
}e[M];

int n , m , k , cnt , extra[15] , cost[15] , cnt_add[15] , fa[N+10];
int find(int x)
{
	if (x == fa[x])return x;
	else return fa[x] = find(fa[x]);
}


bool cmp(edge x , edge y)
{
	return x.w < y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int a,b,c,i = 1;i <= m;i++)
	{
		cin >> a >> b >> c;
		e[++cnt] = {a,b,c};
	}
	for (int i = 1;i <= n+k*2;i++)fa[i] = i;
	for (int ct,i = 1;i <= k;i++)
	{
		cin >> e[++cnt].w;
		ct = e[cnt].w;
		cost[i] = ct;
		e[cnt].u = i+n;
		e[cnt].v = i+k+n;
		extra[i] = 2e9;
		for (int j = 1;j <= n;j++)
		{
			int p;
			cin >> p;
			extra[i] = min(extra[i],p);
			e[++cnt] = {i+n,j,p+ct};
		}
		extra[i] += ct;
		//cout << extra[i] << endl;
	}
	sort(e+1,e+1+cnt,cmp);
	long long ans = 0;
	int tot = n+k*2;
	for (int i = 1;i <= cnt;i++)
	{
		int u = e[i].u, v = e[i].v;
		//cout << e[i].w << ' ';
		if (find(u) != find(v))
		{
			fa[find(u)] = find(v);
			//cout << u << ' ' << v << endl;
			ans+=e[i].w;
			if (u > n && u <= n+k && v <= n)ans -= cost[u-n];
			tot--;
			if (u > n && u <= n+k)cnt_add[u-n]++;
		}
		if (tot == 1)break;
	}
	//cout << endl;
	for (int i = 1;i <= k;i++)
	{ 
		//cout << "p" << cnt_add[i] << endl;
		if (cnt_add[i] == 2)
		{
			ans -= extra[i];
		}
	}
	cout << ans;
	return 0;
}
