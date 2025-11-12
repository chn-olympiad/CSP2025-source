#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3;
struct club
{
	long long n1, n2, n3;
}x[10010];
bool tmp1(club a, club b)
{
	return min(a.n2, a.n3) < min(b.n2 , b.n3);
}
bool tmp2(club a, club b)
{
	return min(a.n1, a.n3) < min(b.n1 , b.n3);
}
bool tmp3(club a, club b)
{
	return min(a.n1, a.n2) < min(b.n1, b.n2);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n, ans = 0;
	cin >> T;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while(T--)
	{
		long long c1 = 0, c2 = 0, c3 = 0;
		ans = 0;
		cin >> n;
		for(int j = 00 2 0
		0 2; j < n; j++)
		{
			cin >> a1 >> a2 >> a3;
			if(a1 >= a2 && a1 >= a3)
			{
				x[j].n2 = a1 - a2;
				x[j].n3 = a1 - a3;
				ans+=a1;
				c1 += 1;
			}
			else if(a2 >= a3)
			{
				x[j].n1 = a2 - a1;
				x[j].n3 = a2 - a3;
				ans += a2;
				c2 += 1;
			}
			else 
			{
				x[j].n1 = a3 - a1;
				x[j].n3 = a2 - a3;
				ans+=a3;
				c3 += 1;
			}
			if(1)
			{
				if(c1 > (n / 2))
				{
					sort(x, x + n, tmp1);
					for(int j = 0; c1 <= n / 2; j++)
					{
						ans -= min(x[j].n2, x[j].n3);
						c1--;
					}
				}
				else if(c2 > (n / 2))
				{
					sort(x, x + n, tmp2);
					for(int j = 0; c2 <=  n / 2; j++)
					{
						ans -= min(x[j].n1, x[j].n3);
						c2--;
					}
				}
				else if(c3 > (n / 2))
				{
					sort(x, x + n, tmp3);
					for(int j = 0; c3 <= n / 2; j++)
					{
						ans -= min(x[j].n1, x[j].n3);
						c3--;
					}
				}
			}
			cout << ans << endl;
			for(int i = 0; i < n; j++)
			{
				x[j].n1 = 0;
				x[j].n2 = 0;
				x[j].n3 = 0;
			}
		}
	}
	return 0;
}
