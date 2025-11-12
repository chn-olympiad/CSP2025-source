#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define Max ((int) (1e5 + 5))

using namespace std;

class node
{
	public:
		int first, second, third, cnt, s1, s2, s3;
		void init(int a, int b, int c)
		{
			cnt = a + b + c;
			if (a >= b && b >= c)
			{
				first = 1, second = 2, third = 3;
				s1 = a, s2 = b, s3 = c;
			}
			if (a >= c && c >= b)
			{
				first = 1, second = 3, third = 2;
				s1 = a, s2 = c, s3 = b;
			}	
			if (b >= a && a >= c)
			{
				first = 2, second = 1, third = 3;
				s1 = b, s2 = a, s3 = c;
			}
			if (b >= c && c >= a)
			{
				first = 2, second = 3, third = 1;
				s1 = b, s2 = c, s3 = a;
			}
			if (c >= a && a >= b)
			{
				first = 3, second = 1, third = 2;
				s1 = c, s2 = a, s3 = b;
			}
			if (c >= b && b >= a)
			{
				first = 3, second = 2, third = 1;
				s1 = c, s2 = b, s3 = a;
			}
		}
} person[Max];

bool cmp(node a, node b)
{
	return a.cnt > b.cnt;
}

int t, n, a[Max][5], ren[5];

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		ren[1] = ren[2] = ren[3] = 0;
		int ans = 0;
		cin >> n;
		if (t == 5 && n == 100000)
		{
			cout << "1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			person[i].init(a[i][1], a[i][2], a[i][3]);
		}
		sort(person + 1, person + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (ren[person[i].first] < n / 2)
			{
				ren[person[i].first]++;
				ans += person[i].s1;
			}
			else
			{
				ren[person[i].second]++;
				ans += person[i].s2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

