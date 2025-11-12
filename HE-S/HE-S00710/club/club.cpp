#include<bits/stdc++.h>
#define int long long 
#define Blue_Archive return 0
using namespace std;
constexpr int N = 1e5 + 7;

int T;
int n;
int ans;
int cnt[4];
int a[N][4];

priority_queue<int,vector<int>,greater<int>> q[4];

inline void work()
{
	cin >> n;
	ans = 0;
	for(int i = 1;i <= 3;i ++)
	{
		while(q[i].size()) q[i].pop();
		cnt[i] = 0;
	}
	for(int i = 1,mx;i <= n;i ++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		mx = max(a[i][1],max(a[i][2],a[i][3]));
		if(mx == a[i][1])
		{
			cnt[1] ++;
			q[1].push(min(a[i][1] - a[i][2],a[i][1] - a[i][3]));
		}
		else if(mx == a[i][2])
		{
			cnt[2] ++;
			q[2].push(min(a[i][2] - a[i][1],a[i][2] - a[i][3]));
		}
		else if(mx == a[i][3])
		{
			cnt[3] ++;
			q[3].push(min(a[i][3] - a[i][1],a[i][3] - a[i][2]));
		}
		ans += mx;
	}
	int op = -1;
	for(int i = 1;i <= 3;i ++) if(cnt[i] > n / 2) op = i;
	if(op != -1)
	{
		cnt[op] -= n / 2;
		while(cnt[op])
		{
			int u = q[op].top();
			q[op].pop();
			ans -= u;
			cnt[op] --;
		}
	}
	cout << ans << '\n';
}

signed main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	// freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T --) work();
	Blue_Archive;
}