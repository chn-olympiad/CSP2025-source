#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
int n;
int a[maxn][3],yx[3],cnt[3];
int b[maxn];
int am[maxn]; 
int T;
int sum1,sum2,ma;
int dr;
int ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		sum1 = 0;
		sum2 = 0;
		ma = -1;
		yx[0] = 0;
		yx[1] = 0;
		yx[2] = 0;
		cnt[0] = 0;
		cnt[1] = 0;
		cnt[2] = 0;
		dr = 0;
		ans = 0;	
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			{
				am[i] = 0;
				yx[0] += a[i][0];
				cnt[0]++;
			}
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			{
				am[i] = 1;
				yx[1] += a[i][1];
				cnt[1]++; 
			}
			else if(a[i][2] >= a[i][0] && a[i][2] >= a[i][1])
			{
				am[i] = 2;
				yx[2] += a[i][2];
				cnt[2]++;
			}
		}
		sum1 = yx[0] + yx[1] + yx[2];
		ans += sum1;
		if(cnt[0] > n/2)
		{
			ma = 0;
		}
		else if(cnt[1] > n/2)
		{
			ma = 1;
		}
		else if(cnt[2] > n/2)
		{
			ma = 2;
		}
		if(ma==-1)
		{
			cout << ans << '\n';
			continue;
		}
		dr = cnt[ma] - n/2;
		priority_queue<int,vector<int>,greater<int>> q;
		if(ma==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(am[i] == ma)
				{
					q.push(min(a[i][0] - a[i][1],a[i][0] - a[i][2]));
				}
			}
		}
		else if(ma==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(am[i] == ma)
				{
					q.push(min(a[i][1] - a[i][0],a[i][1] - a[i][2]));
				}
			}
		}
		else if(ma==2)
		{
			for(int i=1;i<=n;i++)
			{
				if(am[i] == ma)
				{
					q.push(min(a[i][2] - a[i][0],a[i][2] - a[i][1]));
				}
			}
		}
		for(int i=1;i<=dr;i++)
		{
			sum2 += q.top();
			q.pop();
		}
		ans -= sum2;
		cout << ans << '\n';
	}
	return 0;	
} 
