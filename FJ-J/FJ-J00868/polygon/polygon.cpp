#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long mod = 998244353;
bool flag = true;
int n , len[N] , mx , sum;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> len[i];
		if(len[i] != 1)
		{
			flag = false;
		}
	}
	if(flag)
	{
		for(int i = 3;i <= n;i++)
		{
			long long num = 1;
			for(int j = n;j >= n - i + 1;j--)
			{
				num *= j;
				num %= mod;
			}
			for(int j = 1;j <= i;j++)
			{
				num /= j;
			}
			ans += num;
		}
		ans %= mod;
		cout << ans;
		return 0;
	}
	for(int i = 0;i < (1 << n);i++)
	{
		mx = sum = 0;
		if(__builtin_popcount(i) >= 3)
		{
			int cnt = 1;
			int num = i;
			while(num)
			{
				if(num & 1 == 1)
				{
					mx = max(mx , len[cnt]);
					sum += len[cnt];
				}
				num >>= 1;
				cnt++;
			}
			if(sum > 2 * mx)
			{
				ans++;
			}
		}
	}
	ans %= mod;
	cout << ans;
	return 0;
}
