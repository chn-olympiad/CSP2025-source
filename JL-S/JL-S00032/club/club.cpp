#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
struct A
{
	int a, b, c;
	int f, s, t;
	int i;
}pe[N];

int imtc(int a, int b, int c)
{
	return max (a, max (b, c));
}

void ugly(int i)
{
	if (imtc(pe[i].a, pe[i].b, pe[i].c) == pe[i].a)
	{ pe[i].f = 1;
		if (pe[i].b >= pe[i].c) pe[i].s = 2, pe[i].t = 3;
		else pe[i].s = 3, pe[i].t = 2;
	}
	else if (imtc(pe[i].a, pe[i].b, pe[i].c) == pe[i].b)
	{ pe[i].f = 2;
		if (pe[i].a >= pe[i].c) pe[i].s = 1, pe[i].t = 3;
		else pe[i].s = 3, pe[i].t = 1;
	}
	else if (imtc(pe[i].a, pe[i].b, pe[i].c) == pe[i].c)
	{ pe[i].f = 3;
		if (pe[i].a >= pe[i].b) pe[i].s = 1, pe[i].t = 2;
		else pe[i].s = 2, pe[i].t = 1;
	}
}

bool cmpab(A n, A m)
{
	int a1 = min (n.c - n.a, n.c - n.b);
	int a2 = min (m.c - m.a, m.c - m.b);
	
	return a1 < a2;
}
bool cmpbc(A n, A m)
{
	int a1 = min (n.a - n.c, n.a - n.b);
	int a2 = min (m.a - m.c, m.a - m.b);
	
	return a1 < a2;
}
bool cmpac(A n, A m)
{
	int a1 = min (n.b - n.a, n.b - n.c);
	int a2 = min (m.b - m.a, m.b - m.c);
	
	return a1 < a2;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	
	while (t --)
	{
		int a = 0, b = 0, c = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			cin >> pe[i].a >> pe[i].b >> pe[i].c;
			pe[i].i = i;
			ugly(i);
			if (pe[i].f == 1) a ++;
			else if (pe[i].f == 2) b ++;
			else if (pe[i].f == 3) c ++;
		}
		//cout << a << " " << b << " " << c << endl;
		if (a > n / 2)
		{
			sort (pe + 1, pe + 1 + n, cmpbc);
			int aa = 0;
			for (int i = 1; i <= n; i ++)
			{
				if (pe[i].f == 1)
				{
					int qwer = pe[i].f;
					pe[i].f = pe[i].s;
					pe[i].s = pe[i].t;
					pe[i].t = qwer;
					
					aa ++;
				}
				if (aa + n / 2 == a) break;
			}
		}
		else if (b > n / 2)
		{
			sort (pe + 1, pe + 1 + n, cmpac);
			int bb = 0;
			for (int i = 1; i <= n; i ++)
			{
				if (pe[i].f == 2)
				{
					int qwer = pe[i].f;
					pe[i].f = pe[i].s;
					pe[i].s = pe[i].t;
					pe[i].t = qwer;
					
					bb ++;
				}
				if (bb + n / 2 == b) break;
			}
		}
		else if (c > n / 2)
		{
			sort (pe + 1, pe + 1 + n, cmpab);
			int cc = 0;
			for (int i = 1; i <= n; i ++)
			{
				if (pe[i].f == 3)
				{
					int qwer = pe[i].f;
					pe[i].f = pe[i].s;
					pe[i].s = pe[i].t;
					pe[i].t = qwer;
					
					cc ++;
				}
				if (cc + n / 2 == c) break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (pe[i].f == 1) ans += pe[i].a;
			else if (pe[i].f == 2) ans += pe[i].b;
			else if (pe[i].f == 3) ans += pe[i].c;
		}
		cout << ans << endl;
	}
}
