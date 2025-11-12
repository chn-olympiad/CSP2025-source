#include <bits/stdc++.h>
using namespace std;

#define ms(x) memset(x, 0, sizeof(x));
int n;
struct node
{
	int a1, a2, a3, t;
}a[100005], c1[100005], c2[100005], c3[100005], d[100005], e[100005], f[100005], g[100005], h[100005];
int top1, top2, top3, topd, tope, topf, topg, toph;
bool cmp1(node x, node y)
{
	return x.a1 - max(x.a2, x.a3) > y.a1 - max(y.a2, y.a3);
}
bool cmp2(node x, node y)
{
	return x.a2 - max(x.a1, x.a3) > y.a2 - max(y.a1, y.a3);
}
bool cmp3(node x, node y)
{
	return x.a3 - max(x.a2, x.a1) > y.a3 - max(y.a2, y.a1);
}
bool cmp4(node x, node y)
{
	return x.a1 - max(x.a2, x.a3) - min(x.a3 - max(x.a2, x.a1), x.a2 - max(x.a1, x.a3)) < y.a1 - max(y.a2, y.a3) - min(y.a3 - max(y.a2, y.a1), y.a2 - max(y.a1, y.a3));
}
bool cmp5(node x, node y)
{
	return x.a2 - max(x.a1, x.a3) - min(x.a3 - max(x.a2, x.a1), x.a1 - max(x.a2, x.a3)) < y.a2 - max(y.a1, y.a3) - min(y.a3 - max(y.a2, y.a1), y.a1 - max(y.a2, y.a3));
}
bool cmp6(node x, node y)
{
	return x.a3 - max(x.a1, x.a2) - min(x.a1 - max(x.a2, x.a3), x.a2 - max(x.a1, x.a3)) < y.a3 - max(y.a1, y.a2) - min(y.a1 - max(y.a2, y.a3), y.a2 - max(y.a1, y.a3));
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		sort(a + 1, a + n + 1, cmp1);
		while (a[top1 + 1].a1 - max(a[top1 + 1].a2, a[top1 + 1].a3) >= 0 && top1 < n / 2)
			top1++, c1[top1] = a[top1], a[top1].t = 1;
		for (int i = 1; i <= n; i++)
			if (!a[i].t)
				d[++topd] = a[i];
		sort(d + 1, d + topd + 1, cmp2);
		while (d[top2 + 1].a2 - max(d[top2 + 1].a1, d[top2 + 1].a3) >= 0 && top2 < n / 2 && top2 < topd)
			top2++, c2[top2] = d[top2], d[top2].t = 1;
		for (int i = 1; i <= topd; i++)
			if (!d[i].t)
				e[++tope] = d[i];
		sort(e + 1, e + tope + 1, cmp3);
		while (e[top3 + 1].a3 - max(e[top3 + 1].a1, e[top3 + 1].a2) >= 0 && top3 < n / 2 && top3 < tope)
			top3++, c3[top3] = e[top3], e[top3].t = 1;
		for (int i = 1; i <= tope; i++)
			if (!e[i].t)
				f[++topf] = e[i];
		if (top1 < n / 2)
		{
			sort(f + 1, f + topf + 1, cmp4);
			while (f[top1 + 1].a1 - max(f[top1 + 1].a2, f[top1 + 1].a3) >= min(f[top1 + 1].a3 - max(f[top1 + 1].a2, f[top1 + 1].a1), f[top1 + 1].a2 - max(f[top1 + 1].a1, f[top1 + 1].a3)) && top1 < n / 2 && top1 < topf)
				top1++, c1[top1] = f[top1], f[top1].t = 1;
		}
		for (int i = 1; i <= topf; i++)
			if (!f[i].t)
				g[++topg] = f[i];
		if (top2 < n / 2)
		{
			sort(g + 1, g + topg + 1, cmp5);
			while (g[top2 + 1].a2 - max(g[top2 + 1].a1, g[top2 + 1].a3) >= min(g[top2 + 1].a3 - max(g[top2 + 1].a2, g[top2 + 1].a1), g[top2 + 1].a1 - max(g[top2 + 1].a2, g[top2 + 1].a3)) && top2 < n / 2 && top2 < topg)
				top2++, c2[top2] = g[top2], g[top2].t = 1;
		}
		for (int i = 1; i <= topg; i++)
			if (!g[i].t)
				h[++toph] = g[i];
		if (top3 < n / 2)
		{
			sort(h + 1, h + toph + 1, cmp6);
			while (h[top3 + 1].a3 - max(h[top3 + 1].a1, h[top3 + 1].a2) >= min(h[top3 + 1].a2 - max(h[top3 + 1].a3, h[top3 + 1].a1), h[top3 + 1].a1 - max(h[top3 + 1].a2, h[top3 + 1].a3)) && top3 < n / 2 && top3 < toph)
				top3++, c3[top3] = h[top3], h[top3].t = 1;
		}
		long long ans = 0;
		for (int i = 1; i <= top1; i++)
			ans += c1[i].a1;
		for (int i = 1; i <= top2; i++)
			ans += c2[i].a2;
		for (int i = 1; i <= top3; i++)
			ans += c3[i].a3;
		for (int i = 1; i <= toph; i++)
			if (!h[i].t)
				ans += min(h[i].a1, min(h[i].a2, h[i].a3));
		ms(a);
		ms(c1)
		ms(c2);
		ms(c3);
		ms(d)
		ms(e)
		ms(f);
		ms(g);
		ms(h);
		top1 = top2 = top3 = topd = tope = topf = topg = toph = 0;
		cout << ans << '\n';
	}

	
	return 0;
}