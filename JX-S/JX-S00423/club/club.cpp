#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
	int a, b, c;
	int ch;
};

struct sub
{
	int val;
	int to;
	int id;
};

bool cmp(sub x, sub y)
{
	return x.val < y.val;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<node> stu(n); stu.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
		}
		int x1 = 0, x2 = 0, x3 = 0;
		int s1 = 0, s2 = 0, s3 = 0;
		for (int i = 0; i < n; i++)
		{
			int ma = max(stu[i].a, max(stu[i].b, stu[i].c));
			if (stu[i].a == ma)
			{
				x1 += 1;
				s1 += stu[i].a;
				stu[i].ch = 1;
			}
			else if (stu[i].b == ma)
			{
				x2 += 1;
				s2 += stu[i].b;
				stu[i].ch = 2;
			}
			else
			{
				x3 += 1;
				s3 += stu[i].c;
				stu[i].ch = 3;
			}
		}
		if (max(x1, max(x2, x3)) <= n / 2)
		{
			cout << s1 + s2 + s3 << endl;
			continue;
		}
		if (x2 == max(x1, max(x2, x3)))
		{
			for (int i = 0; i < n; i++)
			{
				swap(stu[i].a, stu[i].b);
				if (stu[i].ch != 2)
				{
					stu[i].ch = 0;
				}
			}
			swap(x1, x2);
		}
		else if (x3 == max(x1, max(x2, x3)))
		{
			for (int i = 0; i < n; i++)
			{
				swap(stu[i].a, stu[i].c);
				if (stu[i].ch != 3)
				{
					stu[i].ch = 0;
				}
			}
			swap(x1, x3);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (stu[i].ch != 1)
				{
					stu[i].ch = 0;
				}
			}
		}
		vector<sub> work; work.clear();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (stu[i].ch != 0)
			{
				sub x, y;
				x.val = stu[i].a - stu[i].b; x.to = 2; x.id = i;
				y.val = stu[i].a - stu[i].c; y.to = 3; y.id = i;
				work.push_back(x);
				work.push_back(y);
				cnt += 2;
			}
		}
		int sum = s1 + s2 + s3;
		map<int, int> mp; mp.clear();
		sort(work.begin(), work.end(), cmp);
		for (int i = 0; (i < cnt) && (x1 > n / 2); i++)
		{
			if (mp.find(work[i].id) == mp.end())
			{
				if (work[i].to == 2 && x2 <= n / 2)
				{
					sum -= work[i].val;
					x1--;
					x2++;
					mp[work[i].id] = 1;
				}
				else if (work[i].to == 3 && x3 <= n / 2)
				{
					sum -= work[i].val;
					x1--;
					x3++;
					mp[work[i].id] = 1;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
