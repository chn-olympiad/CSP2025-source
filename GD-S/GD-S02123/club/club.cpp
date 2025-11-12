#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int N = 1e5 + 5;
struct node{
	int x, y, z, best, se;
}a[N];
/*struct edge{
	int y, w;
	bool operator < (const edge &x) const{
		return w < x.w;
	}
}a[N], b[N], c[N];
int stk1[N], tot1, stk2[N], tot2, stk3[N], tot3;*/
struct node1{
	int y, w;
};
vector<node1> list[4];
int stk[N], tot;
int maxn;
/*
bool dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		if(!match[i] || dfs(i))
		{
			match[i] = x;
		}
	}
}*/

void init()
{
	tot = 0;
	for(int i = 0; i < 4; i++) list[i].clear();
}

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		int n;
		scanf("%d", &n);
		bool flag = true;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			stk[++tot] = a[i].x;
			if(a[i].y != 0 || a[i].z != 0) flag = false;
			int x = a[i].x, y = a[i].y, z = a[i].z;
			if(x >= y && x >= z)
			{
				a[i].best = 1;
				if(y >= z) a[i].se = 2;
				else a[i].se = 3;
				list[1].push_back({i, x});
			}
			else if(y >= x && y >= z)
			{
				a[i].best = 2;
				if(x >= z) a[i].se = 1;
				else a[i].se = 3;
				list[2].push_back({i, y});
			}
			else if(z >= x && z >= y)
			{
				a[i].best = 3;
				if(x >= y) a[i].se = 1;
				else a[i].se = 2;
				list[3].push_back({i, z});
			}
		}
		if(n == 2)
		{
			bool f = true;
			for(int i = 1; i <= 3; i++)
			{
				if(list[i].size() > 1)
				{
					f = false;
					break;
				}
			}
			if(f)
			{
				printf("%d\n", list[a[1].best][0].w + list[a[2].best][0].w);
			}
			else
			{
				int best1 = max({a[1].x, a[1].y, a[1].z}), best2 = max({a[1].x, a[1].y, a[1].z});
				int miner1 = min({a[1].x, a[1].y, a[1].z}), miner2 = min({a[1].x, a[1].y, a[1].z});
				int se1, se2;
				if(a[1].x != best1 && a[1].x != miner1) se1 = a[1].x;
				else if(a[1].y != best1 && a[1].y != miner1) se1 = a[1].y;
				else if(a[1].z != best1 && a[1].z != miner1) se1 = a[1].z;
				if(a[2].x != best2 && a[2].x != miner2) se2 = a[2].x;
				else if(a[2].y != best2 && a[2].y != miner2) se2 = a[2].y;
				else if(a[2].z != best2 && a[2].z != miner2) se2 = a[2].z;
				printf("%d\n", max(best1 + se2, se1 + best2));
			}
			continue;
		}
		maxn = n / 2;
		if(flag)
		{
			sort(stk + 1, stk + tot + 1, cmp);
			int ans = 0;
			for(int i = 1; i <= maxn; i++)
			{
				ans += stk[i];
			}
			printf("%d\n", ans);
			continue;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
