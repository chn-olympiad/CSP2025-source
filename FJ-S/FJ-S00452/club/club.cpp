#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int t, n;
struct node
{
	int a, b, c;
}x[N];

struct qqq
{
	int v, id;
	bool operator < (const qqq &r) const
	{ return v > r.v; }
};
priority_queue<qqq> q1, q2, q3;

bool cmp1(const node &l, const node &r)
{ return l.a > r.a; }

bool cmp2(const node &l, const node &r)
{ return l.a + l.b + l.c < r.a + r.b + r.c; }

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool f1 = true, f2 = true;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i].a >> x[i].b >> x[i].c;
			if(x[i].b != 0 || x[i].c != 0) f1 = false;
			if(x[i].c != 0) f2 = false;
		}
		if(n == 2)
		{
			cout << max({max(x[1].a + x[2].b, x[1].a + x[2].c), max(x[1].b + x[2].a, x[1].b + x[2].c), max(x[1].c + x[2].a, x[1].c + x[2].b)});
			continue;
		}
		if(f1)
		{
			int ans = 0;
			sort(x + 1, x + n + 1, cmp1);
			for(int i = 1; i <= n / 2; i++)
				ans += x[i].a;
			cout << ans << endl;
			continue;
		}
		if(f2)
		{
			for(int i = 1; i <= n; i++)
			{
				if(x[i].a > x[i].b)
				{
					if(q1.size() < n / 2) q1.push(qqq{x[i].a, i});
					else if(x[q1.top().id].b + x[i].a > q1.top().v)
					{
						qqq u = q1.top(); q1.pop();
						q1.push(qqq{x[i].a, i});
						if(q2.size() < n / 2) q2.push(qqq{x[u.id].b, u.id});
						else if(q2.top().v < x[u.id].b)
						{
							q2.pop();
							q2.push(qqq{x[u.id].b, u.id});
						}
					}
				}
				else
				{
					if(q2.size() < n / 2) q2.push(qqq{x[i].b, i});
					else if(x[q2.top().id].a + x[i].b > q2.top().v)
					{
						qqq u = q2.top(); q2.pop();
						q2.push(qqq{x[i].b, i});
						if(q1.size() < n / 2) q1.push(qqq{x[u.id].a, u.id});
						else if(q1.top().v < x[u.id].a)
						{
							q1.pop();
							q1.push(qqq{x[u.id].a, u.id});
						}
					}
				}
			}
			int ans = 0;
			while(!q1.empty()) ans += q1.top().v, q1.pop();
			while(!q2.empty()) ans += q2.top().v, q2.pop();
			cout << ans << endl;
			continue;
		}
		sort(x + 1, x + n + 1, cmp2);
		for(int i = 1; i <= n; i++)
		{
			if(x[i].a > x[i].b && x[i].a > x[i].c)
			{
				if(q1.size() < n / 2) q1.push(qqq{x[i].a, i});
				else if(x[q1.top().id].b + x[i].a > q1.top().v || x[q1.top().id].c + x[i].a > q1.top().v)
				{
					qqq u = q1.top(); q1.pop();
					q1.push(qqq{x[i].a, i});
					if(x[u.id].b + x[i].a > x[u.id].c + x[i].a)
					{
						if(q2.size() < n / 2) q2.push(qqq{x[u.id].b, u.id});
						else if(q2.top().v < x[u.id].b)
						{
							q2.pop();
							q2.push(qqq{x[u.id].b, u.id});
						}
					}
					else
					{
						if(q3.size() < n / 2) q3.push(qqq{x[u.id].c, u.id});
						else if(q3.top().v < x[u.id].c)
						{
							q3.pop();
							q3.push(qqq{x[u.id].c, u.id});
						}
					}
				}
			}
			if(x[i].b > x[i].a && x[i].b > x[i].c)
			{
				if(q2.size() < n / 2) q2.push(qqq{x[i].b, i});
				else if(x[q2.top().id].a + x[i].b > q2.top().v && x[q2.top().id].c + x[i].b > q2.top().v)
				{
					qqq u = q2.top(); q2.pop();
					q2.push(qqq{x[i].b, i});
					if(x[u.id].a + x[i].b > x[u.id].c + x[i].b)
					{
						if(q1.size() < n / 2) q1.push(qqq{x[u.id].a, u.id});
						else if(q1.top().v < x[u.id].a)
						{
							q1.pop();
							q1.push(qqq{x[u.id].a, u.id});
						}
					}
					else
					{
						if(q3.size() < n / 2) q3.push(qqq{x[u.id].c, u.id});
						else if(q3.top().v < x[u.id].c)
						{
							q3.pop();
							q3.push(qqq{x[u.id].c, u.id});
						}
					}
				}
			}
			if(x[i].c > x[i].b && x[i].c > x[i].a)
			{
				if(q3.size() < n / 2) q3.push(qqq{x[i].c, i});
				else if(x[q3.top().id].b + x[i].c > q3.top().v && x[q3.top().id].a + x[i].c > q3.top().v)
				{
					qqq u = q3.top(); q3.pop();
					q3.push(qqq{x[i].c, i});
					if(x[u.id].a + x[i].c > x[u.id].b + x[i].c)
					{
						if(q1.size() < n / 2) q1.push(qqq{x[u.id].a, u.id});
						else if(q1.top().v < x[u.id].a)
						{
							q1.pop();
							q1.push(qqq{x[u.id].a, u.id});
						}
					}
					else
					{
						if(q2.size() < n / 2) q2.push(qqq{x[u.id].b, u.id});
						else if(q2.top().v < x[u.id].b)
						{
							q2.pop();
							q2.push(qqq{x[u.id].b, u.id});
						}
					}
				}
			}
		}
		int ans = 0;
		while(!q1.empty()) ans += q1.top().v, q1.pop();
		while(!q2.empty()) ans += q2.top().v, q2.pop();
		while(!q3.empty()) ans += q3.top().v, q3.pop();
		cout << ans << endl;
	}
	return 0;
}
