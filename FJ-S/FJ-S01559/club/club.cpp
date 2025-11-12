#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[4], cnt[4];
long long ans;
struct Node
{
	int a, b;
	bool operator < (Node x) const
	{
		return a - b > x.a - x.b;
	}
};
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		priority_queue<Node> q1, q2, q3;
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[1] >> a[2] >> a[3];
			int x = max(max(a[1], a[2]), a[3]);
			if(x == a[1])
			{
				int k = max(a[2], a[3]);
				q1.push({a[1], k});
				if(cnt[1] == n / 2)
				{
					Node u = q1.top();
					if(x > u.a - u.b)
					{
						ans += x - u.a + u.b;
						q1.pop();
					}else ans += k;
				}else
					ans += x, cnt[1]++;
			}else if(x == a[2])
			{
				int k = max(a[1], a[3]);
				q2.push({a[2], k});
				if(cnt[2] == n / 2)
				{
					Node u = q2.top();
					if(x > u.a - u.b)
					{
						ans += x - u.a + u.b;
						q2.pop();
					}else ans += k;
				}else
					ans += x, cnt[2]++;
			}else
			{
				int k = max(a[1], a[2]);
				q3.push({a[3], k});
				if(cnt[3] == n / 2)
				{
					Node u = q3.top();
					if(x > u.a - u.b)
					{
						ans += x - u.a + u.b;
						q3.pop();
					}else ans += k;
				}else
					ans += x, cnt[3]++;
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}
