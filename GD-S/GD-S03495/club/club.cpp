#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e2 + 5; 

int n, t; ll ans, a[MAXN][3], tmp[MAXN]; priority_queue <ll, vector <ll>, greater <ll> > pq;

void dfs(int len, int cnt1, int cnt2, int cnt3)
{
	if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
	
	if (len == n)
	{
		ll t = 0;
		
		for (int i = 1; i <= n; i ++)
		{
			t += a[i][tmp[i]];
		}
		
		ans = max(ans, t); return;
	}
	
	tmp[len + 1] = 0; dfs(len + 1, cnt1 + 1, cnt2, cnt3); tmp[len + 1] = 0;
	
	tmp[len + 1] = 1; dfs(len + 1, cnt1, cnt2 + 1, cnt3); tmp[len + 1] = 0;
	
	tmp[len + 1] = 2; dfs(len + 1, cnt1, cnt2, cnt3 + 1); tmp[len + 1] = 0;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	while (t --)
	{
		cin >> n; ans = 0; memset(tmp, 0, sizeof tmp); sizeof (a, 0, sizeof a); bool flag = false;
		
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2]; pq.push(a[i][0]);
			
			if (a[3] != 0) flag = true;
		}
		
		if (!flag)
		{
			ll t = 0;
			
			for (int i = 1; i <= n / 2; i ++)
			{
				t += pq.top(); pq.pop();
			}
			
			cout << t << "\n"; continue;
		}
		
		dfs(0, 0, 0, 0); cout << ans << "\n";
	}
	
	return 0;
}
