#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e4 + 10, M = 1e6 + 10 + 1e5;
int n, m, k;
LL c[20], a[15][N], fa[N + 10]; 
int cnt, cntt;
LL ans = 1e18;

int get(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = get(fa[x]);
}

struct rec{int x, y; LL z;} edge[M];
struct recc{int x, y; LL z;} edgee[M];

bool cmp(recc a, recc b)
{
	return a.z < b.z;
}


LL sum = 0;
void dfs()
{
	for(int h = 0; h < (1 << k); h++)
	{
		int hh = h, ind = 1;
		while(hh)
		{
			if(hh & 1) 
			{
				for(int i = 1; i <= n; i++)
				{
					edgee[++cntt] = {ind + m, i, a[ind][i]};
				} 
				sum += c[ind];
			}
			hh >>= 1;
			ind++;
		}
			
		for(int i = 1; i <= n + k; i++)  fa[i] = i;
		
		
		sort(edgee + 1, edgee + cntt + 1, cmp);
		
		
		for(int i = 1; i <= cntt; i++)
		{
			int x = get(edgee[i].x), y = get(edgee[i].y);
			
			if(x == y) continue;
			fa[x] = y; 
			sum += edgee[i].z;
		}
		//cout << sum << endl;
		ans = min(ans, sum);
		
		for(int i = 1; i <= cnt; i++)
		{
			edgee[i].x = edge[i].x; edgee[i].y = edge[i].y; edgee[i].z = edge[i].z;
		}	
		cntt = cnt;
		sum = 0;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= m; i++)
	{
		int x, y; 
		LL z;
		scanf("%d%d%lld", &x, &y, &z);
		edge[++ cnt] = {x, y, z};
		edgee[++ cntt] = {x, y, z};
	} 
	
	bool flag = true; LL res = 1e18;
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++)
		{
			scanf("%lld", &a[i][j]);
			if(a[i][j] != 0) flag = false;
		}	
			
		if(flag) res = min(res, c[i]);
	}

	if(flag) 
	{
		cout << res << endl;
		return 0;
	}
	
	dfs();
	
	printf("%lld", ans);
	return 0;
}
