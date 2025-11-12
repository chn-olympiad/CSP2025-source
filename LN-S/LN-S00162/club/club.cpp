#include <bits/stdc++.h>
using namespace std;
#define T long long
bool vis[100005];
int n, ans, u[4], use, a[100005][3], t;
priority_queue<pair<T, T>> q13, q23, q12; //first = num,second = plase
priority_queue<tuple<T, T, T>> q;		  //0 = plase,1 = sum,2 = target
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] == a[i][2] && a[i][2] == a[i][3])
			{
				ans += a[i][1];
				a[i][1] = a[i][2] = a[i][3] = 0;
				vis[i] = 1;
				use++;
			}
		}
		//max({u[1],u[2],u[3]})<=n/2
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				continue;
			}
			if (a[i][3] > max(a[i][1], a[i][2]))
			{
				q.push({i, a[i][3], 3});
			}
			else if (a[i][2] > max(a[i][1], a[i][3]))
			{
				q.push({i, a[i][2], 2});
			}
			else if (a[i][1] > max(a[i][3], a[i][2]))
			{
				q.push({i, a[i][1], 1});
			}
			else
			{
				if (a[i][1] == a[i][2])
				{
					q12.push({a[i][1], i});
				}
				if (a[i][1] == a[i][3])
				{
					q13.push({a[i][1], i});
				}
				if (a[i][2] == a[i][3])
				{
					q23.push({a[i][2], i});
				}
			}
		}
		while (max({u[1], u[2], u[3]}) < n / 2 && !q.empty())
		{
			if (get<2>(q.top()) == 1)
			{
				if (!q13.empty() && !q12.empty() && q12.top().first > get<1>(q.top()) && q12.top().first > q13.top().first)
				{
					ans += q12.top().first;
					vis[q12.top().second] = 1;
					q12.pop();
				}
				else if (!q13.empty() && q13.top().first > get<1>(q.top()))
				{
					ans += q13.top().first;
					vis[q13.top().second] = 1;
					q13.pop();
				}
				else
				{
					ans += get<1>(q.top());
					vis[get<0>(q.top())] = 1;
					q.pop();
				}
				u[1]++;
			}
			else if (get<2>(q.top()) == 2)
			{
				if (!q12.empty() && !q23.empty() && q12.top().first > get<1>(q.top()) && q12.top().first > q23.top().first)
				{
					ans += q12.top().first;
					vis[q12.top().second] = 1;
					q12.pop();
				}
				else if (!q23.empty() && q23.top().first > get<1>(q.top()))
				{
					ans += q23.top().first;
					vis[q23.top().second] = 1;
					q23.pop();
				}
				else
				{
					ans += get<1>(q.top());
					vis[get<0>(q.top())] = 1;
					q.pop();
				}
				u[2]++;
			}
			else if (get<2>(q.top()) == 3)
			{
				if (!q13.empty() && !q23.empty() && q13.top().first > get<1>(q.top()) && q13.top().first > q23.top().first)
				{
					ans += q13.top().first;
					vis[q13.top().second] = 1;
					q13.pop();
				}
				else if (!q23.empty() && q23.top().first > get<1>(q.top()))
				{
					ans += q23.top().first;
					vis[q23.top().second] = 1;
					q23.pop();
				}
				else
				{
					ans += get<1>(q.top());
					vis[get<0>(q.top())] = 1;
					q.pop();
				}
				u[3]++;
			}
			use++;
		}

		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				a[i][1] = a[i][2] = a[i][3] = 0;
			}
		}
		if (u[1] == n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				a[i][1] = 0;
			}
		}
		else if (u[2] == n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				a[i][2] = 0;
			}
		}
		else if (u[3] == n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				a[i][3] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				ans += max({a[i][1], a[i][2], a[i][3]});
			}
		}
		cout << ans << '\n';

		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		use = ans = u[1] = u[2] = u[3] = 0;
		priority_queue<pair<T, T>>().swap(q12);
		priority_queue<pair<T, T>>().swap(q13);
		priority_queue<pair<T, T>>().swap(q23);
		priority_queue<tuple<T, T, T>>().swap(q);
	}
	return 0;
}
/*
cd ..
cd club
g++ -O2 -std=c++14 -static club.cpp -o club
./club

*/
