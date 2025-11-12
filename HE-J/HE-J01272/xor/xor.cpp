#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],b,c;
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <=n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];	
	}
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			if ((sum[l - 1] ^ sum[r]) == k)
			{
				ans++;
				l = r;
				break;
			}
		}
	}
	cout << ans;
	return 0;
} 
