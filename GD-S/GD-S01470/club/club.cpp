#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//typedef long long LL;
const int MAXN = 100005;
struct peo { int a, b, c; } p[MAXN];
int t_p[MAXN][5];
int n;
bool vis[MAXN];

int nxt_max(int a, int b, int c)
{
	if (a <= b && a >= c || a >= b && a <= c) return a;
	if (b <= a && b >= c || b >= a && b <= c) return b;
	return c;
}

void solve()
{
	memset(vis, false, sizeof(vis));
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].a >> p[i].b >> p[i].c;

//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= 3; j++)
//			cin >> a[i][j];
	
	int N = n / 2;
	int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
	int ans = 0;

	sort(p + 1, p + n + 1, [](peo x, peo y) {
		if ((max({x.a, x.b, x.c}) - nxt_max(x.a, x.b, x.c)) != (max({y.a, y.b, y.c}) - nxt_max(y.a, y.b, y.c))) return (max({x.a, x.b, x.c}) - nxt_max(x.a, x.b, x.c)) >= (max({y.a, y.b, y.c}) - nxt_max(y.a, y.b, y.c));
		else if (x.a != y.a) return x.a > y.a;
		else if (x.b != y.b) return x.b > y.b;
		return x.c > y.c;
	});
	
//	for (int i = 1; i <= n; i++)
//	{
//		if (cnt_1 == N) break;
//		if (vis[i] || max({p[i].a, p[i].b, p[i].c}) != p[i].a) continue; vis[i] = true;
//		ans += p[i].a; cnt_1++;
//		
////		cout << p[i].a << ' ' << p[i].b << ' ' << p[i].c << endl;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		
//		if (cnt_2 == N) break;
//		if (vis[i] || max({p[i].a, p[i].b, p[i].c}) != p[i].b) continue; vis[i] = true;
//		ans += p[i].b; cnt_2++;
////		cout << p[i].a << ' ' << p[i].b << ' ' << p[i].c << endl;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		
//		if (cnt_3 == N) break;
//		if (vis[i] || max({p[i].a, p[i].b, p[i].c}) != p[i].c) continue; vis[i] = true;
//		ans += p[i].c; cnt_3++;
////		cout << p[i].a << ' ' << p[i].b << ' ' << p[i].c << endl;
//	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			
			if (max({p[i].a, p[i].b, p[i].c}) == p[i].a && cnt_1 != N) 
				cnt_1++, ans += p[i].a;
			else if (max({p[i].a, p[i].b, p[i].c}) == p[i].b && cnt_2 != N) 
				cnt_2++, ans += p[i].b;
			else if (max({p[i].a, p[i].b, p[i].c}) == p[i].c && cnt_3 != N) 
				cnt_3++, ans += p[i].c;
			else if (nxt_max(p[i].a, p[i].b, p[i].c) == p[i].a && cnt_1 != N) 
				cnt_1++, ans += p[i].a;
			else if (nxt_max(p[i].a, p[i].b, p[i].c) == p[i].b && cnt_2 != N) 
				cnt_2++, ans += p[i].b;
			else if (nxt_max(p[i].a, p[i].b, p[i].c) == p[i].b && cnt_2 != N) 
				cnt_3++, ans += p[i].c;
			else
			{
				if (cnt_1 != N)
					cnt_1++, ans += p[i].a;
				if (cnt_2 != N)
					cnt_2++, ans += p[i].b;
				else cnt_3++, ans += p[i].c;
			}
		}
	}

	cout << ans << endl;
	
	return ;
}

int main() 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
