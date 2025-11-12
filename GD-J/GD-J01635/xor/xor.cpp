#include <bits/stdc++.h>
using namespace std;

int a[500005];
bool flag[500005];
long long dp[500005][2];

struct node
{
	int st, en, len;	
};
node b[500005];
bool cmp(node x, node y)
{
	return x.en < y.en;
}
bool check(int x)
{
	for(int i = b[x].st; i <= b[x].en; i++)
		if(flag[i])	return false;
	return true;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(flag, 0, sizeof(flag));
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	cin >> a[i];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int last = a[i];
		if(last == k)
		{
			cnt++;
			b[cnt].st = i;
			b[cnt].en = i;
			b[cnt].len = b[cnt].en - b[cnt].st + 1;
		}
		for(int j = i + 1; j <= n; j++)	
		{
			last = last ^ a[j];
			if(last == k)
			{
				cnt++;
				b[cnt].st = i;
				b[cnt].en = j;
				b[cnt].len = b[cnt].en - b[cnt].st + 1;
			}
			
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	memset(dp, 0xc0, sizeof(dp));
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i = 2; i <= cnt; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if(b[i].st <= b[i - 1].en)
		{
			int x = i - 1;
			while(b[i].st <= b[x].en)	x--;
			dp[i][1] = dp[x + 1][0] + 1;
		}
		else dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + 1;	
	}
	cout << max(dp[cnt][0], dp[cnt][1]);
	return 0;
}
