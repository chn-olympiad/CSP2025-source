#include <bits/stdc++.h>
using namespace std;
int n,a[5100],sum = 0,maxx = 0,ans = 0;
const long long N = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int i = n;
	while(i)
	{
		int k = i;
		sum = 0;
		maxx = -0x3f3f3f3f;
		for(int j=1;j<=n;j++)
		{
			if(k)
			{
				sum += a[j] % N;
				maxx = max(maxx,a[j]);
				k--;
			}
		}
		if(sum > maxx) ans ++;
		i--;
	}
	cout << ans % N;
	return 0;
}
