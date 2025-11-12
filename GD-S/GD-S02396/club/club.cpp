#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define spc putchar(32)
#define endl putchar(10)

const int N = 205;

ll ans;
int n, m, op1, op2, op3;
int a[N][4], f[N][N][N];

int rd()
{
	char c = getchar(); int s = 0;
	while(!isdigit(c)) c = getchar();
	do s = (s << 1) + (s << 3) + (c ^ 48), c = getchar(); while(isdigit(c));
	return s;
}

void wr(int x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

void wr(ll x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

struct Sub1
{
	int dfs(int x, int y, int z)
	{
		if(x + y + z == n) return 0;
		if(~f[x][y][z]) return f[x][y][z];
		int res = 0, now = x + y + z + 1;
		if(x < m) res = max(res, dfs(x+1, y, z) + a[now][1]);
		if(y < m) res = max(res, dfs(x, y+1, z) + a[now][2]);
		if(z < m) res = max(res, dfs(x, y, z+1) + a[now][3]);
		return f[x][y][z] = res;
	}
	void work()
	{
		memset(f, -1, sizeof(f));
		m = (n >> 1);
		for(int i = 1; i <= n; ++i) a[i][1] = rd(), a[i][2] = rd(), a[i][3] = rd();
		wr(dfs(0, 0, 0)), endl;
	}
}
_;

struct node
{
	int a, b, c, d, e, f, id;
}
p[100005];

bool cmp1(const node &x, const node &y)
{
	if(op1) return x.d != y.d ? x.d > y.d : (x.e != y.e ? x.e < y.e : x.f < y.f);
	return x.d != y.d ? x.d > y.d : (x.f != y.f ? x.f < y.f : x.e < y.e);
}

bool cmp2(const node &x, const node &y)
{
	if(op2) return x.e != y.e ? x.e > y.e : (x.d != y.d ? x.d < y.d : x.f < y.f);
	return x.e != y.e ? x.e > y.e : (x.f != y.f ? x.f < y.f : x.d < y.d);
}

bool cmp3(const node &x, const node &y)
{
	if(op3) return x.f != y.f ? x.f > y.f : (x.d != y.d ? x.d < y.d : x.e < y.e);
	return x.f != y.f ? x.f > y.f : (x.e != y.e ? x.e < y.e : x.d < y.d);
}

bool cmp4(const node &x, const node &y)
{
	return x.e - x.f > y.e - y.f;
}

bool cmp5(const node &x, const node &y)
{
	return x.d - x.f > y.d - y.f;
}

bool cmp6(const node &x, const node &y)
{
	return x.d - x.e > y.d - y.e;
}

struct Sub2
{
	bool flag[100005];
	void work()
	{
		memset(flag, false, sizeof(flag));
		ll ans = 0;
		bool ok = true;
		for(int i = 1; i <= n; ++i)
		{
			p[i].a = rd(), p[i].b = rd(), p[i].c = rd();
			ok &= (!p[i].c);
			p[i].d = - p[i].b - p[i].c;
			p[i].e = - p[i].a - p[i].c;
			p[i].f = - p[i].a - p[i].b;
			p[i].id = i;
			ans += p[i].a + p[i].b + p[i].c;
		}
		if(ok)
		{
			int A = 0;
			sort(p+1, p+n+1, cmp6);
			for(int i = 1; i <= n; ++i)
			{
				if(flag[p[i].id]) continue;
				if(A >= n / 2) ans += p[i].e;
				else ans += p[i].d, ++A;
			}
		}
		else
		{
			int A = 0, B = 0, C = 0;
			sort(p+1, p+n+1, cmp1);
			for(int i = 1; i <= n; ++i)
			{
				if(flag[p[i].id] || p[i].d < p[i].e || p[i].d < p[i].f) continue;
				flag[p[i].id] = true;
				ans += p[i].d;
				++A;
				if(A >= n / 2) break;
			}
			sort(p+1, p+n+1, cmp2);
			for(int i = 1; i <= n; ++i)
			{
				if(flag[p[i].id] || p[i].e < p[i].f || p[i].e < p[i].d) continue;
				flag[p[i].id] = true;
				ans += p[i].e;
				++B;
				if(B >= n / 2) break;
			}
			sort(p+1, p+n+1, cmp3);
			for(int i = 1; i <= n; ++i)
			{
				if(flag[p[i].id] || p[i].f < p[i].d || p[i].f < p[i].e) continue;
				flag[p[i].id] = true;
				ans += p[i].f;
				++C;
				if(C >= n / 2) break;
			}
			if(A + B + C != n)
			{
				if(A >= n / 2)
				{
					sort(p+1, p+n+1, cmp4);
					for(int i = 1; i <= n; ++i)
					{
						if(flag[p[i].id]) continue;
						if(B >= n / 2) ans += p[i].f;
						else ans += p[i].e, ++B;
					}
				}
				else if(B >= n / 2)
				{
					sort(p+1, p+n+1, cmp5);
					for(int i = 1; i <= n; ++i)
					{
						if(flag[p[i].id]) continue;
						if(A >= n / 2) ans += p[i].f;
						else ans += p[i].d, ++A;
					}
				}
				else
				{
					sort(p+1, p+n+1, cmp6);
					for(int i = 1; i <= n; ++i)
					{
						if(flag[p[i].id]) continue;
						if(A >= n / 2) ans += p[i].e;
						else ans += p[i].d, ++A;
					}
				}
			}
		}
		wr(ans), endl;
	}
}
__;

void solve()
{
	n = rd();
	if(n <= 500) _.work();
	else __.work();
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = rd();
	while(t--) solve();
	return 0;
}
