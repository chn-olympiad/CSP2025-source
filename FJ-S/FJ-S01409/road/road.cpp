#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e4 + 1e3;
const int M = 2e6;

struct edges
{
	int u, v, w;
}e[M];

ll n, m, k, far[N], flagA, c[20], a[20][N], ans, vis[20];

ll fnd(ll now)
{
	if (far[now] == now) return now;
	return far[now] = fnd(far[now]);
}

bool cmp(edges _1, edges _2)
{
	return _1.w < _2.w;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	ll u, v, w;
	for (ll i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		e[i].u = u; e[i].v = v; e[i].w = w;
	}
	
	ll flag1 = 1, flag2 = 1;
	for (ll i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (c[i] != 0) flag1 = 0;
		int flag3 = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)flag3 = 1;
		}
		if (flag3 == 0)flag2 = 0;
	}
	
	if (flag1 && flag2) flagA = 1;
	
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)far[i] = i;
		sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			ll far1 = fnd(e[i].u), far2 = fnd(e[i].v);
//			cout << "fori: " << i << " " << far1 << " " << far2 << "\n";
			if (far1 == far2) continue;
			ans += e[i].w;
			far[far1] = far2;
		}
		cout << ans << "\n";
		return 0;
	}
	
	if (flagA == 1)
	{
		for (int i = 1; i <= n + k; i++)far[i] = i;
		ll mm = m;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == 0)
				{
					far[j] = n + i;
				}
				else 
				{
					e[++mm].u = n + i;
					e[mm].v = j;
					e[mm].w = a[i][j];
				}
			}
		}
		sort(e + 1, e + mm + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			ll far1 = fnd(e[i].u), far2 = fnd(e[i].v);
//			cout << "fori: " << i << " " << far1 << " " << far2 << "\n";
			if (far1 == far2) continue;
			ans += e[i].w;
			far[far1] = far2;
		}
		cout << ans << "\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i++) far[i] = i;
	
	sort(e + 1, e + m + 1, cmp);
	
	for (int i = 1; i <= m; i++)
	{
		ll far1 = fnd(e[i].u), far2 = fnd(e[i].v);
//		cout << "fori: " << i << " " << far1 << " " << far2 << "\n";
		if (far1 == far2) continue;
		ll minn = 2 * 0x3f3f3f3f, mini = 0;
		for (int j = 1; j <= k; j++)
		{
			ll tmp = 0, tmp1 = 0x3f3f3f3f, tmp2 = 0x3f3f3f3f;
			if (!vis[j]){tmp = c[j];}
			for (int l = 1; l <= n; l++)
			{
				if (far[l] == far1) {tmp1 = min(tmp1, a[j][l]);}
				else if (far[l] == far2) {tmp2 = min(tmp2, a[j][l]);}
			}
			tmp += tmp1; tmp += tmp2;
			if (minn > tmp) 
			{
				minn = tmp;
				mini = j;
			}
			else if (minn == tmp)
			{
//				cout << "_";
				if (!vis[j]) 
				{
					mini = j;
				}
			}
		}
//		cout << "fori: " << i << " ";
		if (minn <= e[i].w)
		{
//			cout << "1: " << minn << "\n";
//			cout << "use: " << mini<<"\n";
			ans += minn;
			vis[mini] = 1;
		}
		else 
		{
//			cout << "2: " << e[i].w << "\n";
			ans += e[i].w;
		}
		far[far1] = far2;
	}
	
	cout << ans << "\n";
	
	return 0;
}
/*

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
