#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn][5];
int t, n;
int mxn[maxn], smx[maxn];
int cnt[5];
struct node
{
	ll sum, id;
	bool operator < (const node &b) const
	{
		return sum > b.sum;
	}
};
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) mxn[i] = smx[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				cnt[j] = 0;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				if(a[i][j] > a[i][mxn[i]])
				{
					smx[i] = mxn[i];
					mxn[i] = j;
				}
				else if(a[i][j] > a[i][smx[i]])
				{
					smx[i] = j;
				}
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans += a[i][mxn[i]];
			cnt[mxn[i]]++;
		}
		priority_queue<node>q;
		for(int j = 1; j <= 3; j++)
		{
			if(cnt[j] > (n >> 1))
			{
				for(int i = 1; i <= n; i++)
				{
					if(mxn[i] == j)
					{
						//cout << a[i][mxn[i]] - a[i][smx[i]] << '\n';
						q.push({a[i][mxn[i]] - a[i][smx[i]], i});
					}
				}
				while(cnt[j] > n / 2 && !q.empty())
				{
					int val = q.top().sum, id = q.top().id;
					//cout << val << '\n';
					ans -= q.top().sum;
					cnt[j]--;
					q.pop();
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
