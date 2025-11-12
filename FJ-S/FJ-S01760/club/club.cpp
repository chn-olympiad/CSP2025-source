#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct huangba{
	int x, y, z, m;
};
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int __ = 1; __ <= T; ++ __)
	{
		int n, sum = 0;
		scanf("%d", &n);
		huangba *p = new huangba[n + 1]();
		vector<pii> x, y, z;
		for (int i = 1; i <= n; ++ i)
		{
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
			if (p[i].x >= p[i].y && p[i].x >= p[i].z)
			{
				p[i].m = p[i].x - max(p[i].y, p[i].z);
				x.push_back({p[i].m, p[i].x});
			}
			else if (p[i].y >= p[i].x && p[i].y >= p[i].z)
			{
				p[i].m = p[i].y - max(p[i].x, p[i].z);
				y.push_back({p[i].m, p[i].y});
			}
			else if (p[i].z >= p[i].y && p[i].z >= p[i].x)
			{
				p[i].m = p[i].z - max(p[i].y, p[i].x);
				z.push_back({p[i].m, p[i].z});
			}
		}
		int a1 = x.size(), a2 = y.size(), a3 = z.size();
		if (a1 <= n / 2 && a2 <= n / 2 && a3 <= n / 2)
		{
			for (auto i : x)
				sum += i.second;
			for (auto i : y)
				sum += i.second;
			for (auto i : z)
				sum += i.second;
		}
		if (a1 > n / 2)
		{
			sort(x.begin(), x.end());
			for (int i = 0; i < a1 - n / 2; ++ i)
				sum -= x[i].first;
			for (auto i : x)
				sum += i.second;
			for (auto i : y)
				sum += i.second;
			for (auto i : z)
				sum += i.second;
		}
		if (a2 > n / 2)
		{
			sort(y.begin(), y.end());
			for (int i = 0; i < a2 - n / 2; ++ i)
				sum -= y[i].first;
			for (auto i : x)
				sum += i.second;
			for (auto i : y)
				sum += i.second;
			for (auto i : z)
				sum += i.second;
		}
		if (a3 > n / 2)
		{
			sort(z.begin(), z.end());
			for (int i = 0; i < a3 - n / 2; ++ i)
				sum -= z[i].first;
			for (auto i : x)
				sum += i.second;
			for (auto i : y)
				sum += i.second;
			for (auto i : z)
				sum += i.second;
		}
		printf("%d\n", sum);
		x.clear();
		y.clear();
		z.clear();
		delete[] p;
	}
	return 0;
}
