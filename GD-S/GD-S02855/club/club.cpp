#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
const int MAXM = 110;

int T;

int n;
int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXM][MAXM][MAXM];

int ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>T;
	while(T--)
	{
		cerr<<T<<'\n';
		ans = 0;
		memset(dp, 0, sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		bool A = true, B = true;
		for(int i=1;i<=n;i++) A &= (!b[i] & !c[i]), B &= !c[i];
		if(n <= 200)
		{
			if(B)
			{
				int cc = 0;
				for(int i=1;i<=n;i++)
				{
					for(int ca=n/2;ca>=0;ca--)
					{
						for(int cb=min(n-ca, n/2);cb>=0;cb--)
						{
							if(ca) dp[ca][cb][cc] = max(dp[ca][cb][cc], dp[ca-1][cb][cc] + a[i]);
							if(cb) dp[ca][cb][cc] = max(dp[ca][cb][cc], dp[ca][cb-1][cc] + b[i]);
							ans = max(ans, dp[ca][cb][cc]);
						}
					}
				}
				cout<<ans<<'\n';
				continue;
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					for(int ca=n/2;ca>=0;ca--)
					{
						for(int cb=n/2;cb>=0;cb--)
						{
							for(int cc=min(n-ca-cb, n/2);cc>=0;cc--)
							{
								if(ca) dp[ca][cb][cc] = max(dp[ca][cb][cc], dp[ca-1][cb][cc] + a[i]);
								if(cb) dp[ca][cb][cc] = max(dp[ca][cb][cc], dp[ca][cb-1][cc] + b[i]);
								if(cc) dp[ca][cb][cc] = max(dp[ca][cb][cc], dp[ca][cb][cc-1] + c[i]);
								ans = max(ans, dp[ca][cb][cc]);
							}
						}
					}
				}
				cout<<ans<<'\n';
				continue; 
			}
		}
		else
		{
			if(A)
			{
				sort(a+1, a+n+1);
				int sum = 0;
				for(int i=n/2+1;i<=n;i++) sum += a[i];
				cout<<sum<<'\n';
				continue;
			}
			else
			{
				int sum = 0;
				for(int i=1;i<=n;i++) sum += max({a[i], b[i], c[i]});
				cout<<sum<<'\n';
			}
		}
	}
	return 0;
}
