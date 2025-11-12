#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[114514][3];
int a[114514][3];



int xxxxxxxxxxx()
{
	
}

signed main()
{
	ifstream cin("club.in");
	ofstream cout("club.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	srand(time(0));
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			ans += max(a[i][0], a[i][1], a[i]][2]);
		}
		
		cout << ans << '\n';
	}
}
