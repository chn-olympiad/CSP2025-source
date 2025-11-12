#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP 0
#define MAXN 2000001
ll n, k, a[MAXN], book[MAXN], dp[MAXN], i;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	book[0]=2000000;
	fr(1, n, i)
	{
		cin >> a[i];
		if(a[i] == k)
		{
			dp[i] = dp[i - 1] + 1;
			a[i] ^= a[i - 1];
			book[a[i]] = i;
			continue;
		}
		a[i] ^= a[i - 1];
		if(!k && !a[i] && a[1])
		{
			dp[i] = max(dp[i-1], 1ll);
		}
		else if(book[a[i] ^ k])
		{
			dp[i] = max(dp[book[a[i] ^ k] ] + 1, dp[i - 1]);
		}
		else
		{
			dp[i] = dp[i-1];
		}
		book[a[i]] = i;
	}
	cout << dp[n];
	return I_AK_CSP;
}
