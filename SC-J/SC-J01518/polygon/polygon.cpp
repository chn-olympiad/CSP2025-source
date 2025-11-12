#include <bits/stdc++.h>
using namespace std;
int a[5005],ans = 0,n;
bool flag[5005];
int b[5005];
int c[5005][5005];
const int MOD = 998244353;
long long qpow(long long a,long long b,long long p)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = ans * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
void dfs(int k,int step,int cnt,int maxn)
{
	if(step > k)
	{
		if(cnt > maxn * 2)
		{
			bool op = 0;
			sort(b + 1,b + k + 1);
			cout << cnt << " " << maxn << endl;
			for(int i = 1; i <= k; i++)
			{
				cout << b[i] << " ";
			}
			cout << endl;
			for(int i = 1; i <= ans; i++)
			{
				if(op == 1)
				{
					break;
				}
				bool op2 = 0;
				for(int j = 1; j <= k; j++)
				{
					if(c[i][j] != b[j])
					{
						op2 = 1;
						break;
					}
				}
				if(op2 == 0)
				{
					op = 1;
				}
			}
			if(op == 0)
			{
				ans++;
				for(int i = 1; i <= k; i++)
				{
					c[ans][i] = b[i];
				}
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			b[step] = i;
			dfs(k,step + 1,cnt + a[i],max(maxn,a[i]));
			flag[i] = 0;
			b[step] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool m = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			m = 1;
		}
	}
	if(n == 3)
	{
		if(a[1] + a[2] + a[3] > 2 * max(a[1],max(a[2],a[3])))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if(m == 0)
	{
		cout << ((qpow(2,n,MOD) % MOD - 1 - n) % MOD - ((n) * (n - 1) / 2) % MOD + MOD) % MOD;
	}
	return 0;
}
