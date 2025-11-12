#include <iostream>
#define ll long long
#define MAXN 5005
#define MOD 998244353
using namespace std;
ll n,a[5005],sum[5005],maxn,sum_1,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	if(n == 3)
	{
		cout << (2 * (max(max(a[1],a[2]),a[3])) < sum[3] ? 1 : 0);
		return 0;
	}
	else if(n <= 20)
	{
		for(int i = 0 ; i < (2 << (n - 1)) ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(1 << (j - 1) & i)
				{
					sum_1 += a[j];
					maxn = max(maxn,a[j]);
					//cout << j << " ";
				}
			}
			if(sum_1 > maxn * 2)
			{
				ans++;
				//cout << "can\n";
			}
			/*else
			{
				cout << "no\n";
			}*/
			sum_1 = 0;
			maxn = 0;
		}
	}
	cout << ans % MOD;
	return 0;
}

