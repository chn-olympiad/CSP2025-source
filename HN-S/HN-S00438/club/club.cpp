#include <bits/stdc++.h>
using namespace std;
int ans;
int t[100005];
int p1[10005], p2[10005], p3[10005];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, a, w1, w2, w3;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		int z1, z2, z3;
		z1 = z2 = z3 = 0;
		for(int j = 1; j <= a; j++)
		{
			cin >> w1 >> w2 >> w3;
			p1[j] = max(max(w1, w2), w3);
			p3[j] = min(min(w1, w2), w3);
			p2[j] = w1;
			if(p2[j] == p1[j] || p2[j] == p3[j])
			{
				p2[j] = w2;
			}
			if(p2[j] == p1[j] || p2[j] == p3[j])
			{
				p2[j] = w3;
			}
			t[j] = p1[j] - p2[j];
		}
		for(int j = 1; j <= a; j++)
		{
			for(int k = j + 1; k <= a; k++)
			{
				if(t[j] < t[k])
				{
					swap(t[j], t[k]);
					swap(p1[j], p1[k]);
				}
			}
		}
		for(int j = 1; j <= a; j++)
		{
			if(max(max(w1, w2), w3) == w1 && z1 <= n / 2)
			{
				ans += w1;
			}
			if(max(max(w1, w2), w3) == w2 && z2 <= n / 2)
			{
				ans += w2;
			}
			if(max(max(w1, w2), w3) == w3 && z3 <= n / 2)
			{
				ans += w3;
			}
		}
		cout << ans;
		ans = 0;
	}
	return 0;
}
