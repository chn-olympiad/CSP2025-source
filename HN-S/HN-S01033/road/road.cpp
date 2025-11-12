#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int f[100005], n, m, k, c[1005], cw[105][10005], cnt, ans, p;
int used[5000005], usedcity[1005], usedcitynum;
int nowEdgenum;
struct edge
{
	int u, v, w, flag, id;
}a[5000005];
int find(int x)
{
	if(f[x] == x) return x;
	return find(f[x]);
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i <= n + k + 114; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		cnt ++;
		cin >> a[cnt].u >> a[cnt].v >> a[cnt].w;
		a[cnt].id = cnt;
	}
	for(int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j ++)
		{
			cin >> cw[i][j];
		}
	}
	p = n;
	if(k != 0)
	{
		for(int i = 1; i <= k; i++)
		{
			p ++;
			for(int j = 1; j <= n; j++)
			{
				cnt ++;
				a[cnt].u = p;
				a[cnt].v = j;
				a[cnt].w = cw[i][j] + c[i];
				a[cnt].flag = i;
				a[cnt].id = cnt;
			}
		}
	}
//		cout << cnt << endl;
//		for(int i = 1; i <= cnt; i ++)
//		{
//			cout << a[i].u << " " << a[i].v << " "<<a[i].w << endl; 
//		}
//		cout << "--------"<<endl;
		sort(a + 1, a + cnt + 1, cmp);
		for(int i = 1; i <= cnt; i++)
		{
			if(used[a[i].id])
			{
				continue;
			}
			int u = a[i].u, v = a[i].v;
			int fu = find(u), fv = find(v);
			if(fu == fv) 
			{
				continue;
			}
			used[a[i].id] = 1;
			f[fu] = fv;
			ans += a[i].w;
			nowEdgenum ++;
			if(nowEdgenum >= usedcitynum + n - 1)
			{
				break;
			}
			if(a[i].flag != 0 && !usedcity[a[i].flag])
			{
				usedcitynum ++;
				usedcity[a[i].flag] = 1;
				for(int j = 1; j <= cnt; j ++)
				{
					if(a[j].flag == a[i].flag) a[j].w -= c[a[i].flag];
				}
				sort(a + 1, a + cnt + 1, cmp);
				i = 0;
			}
		}
		cout << ans << endl;
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

