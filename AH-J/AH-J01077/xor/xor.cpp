#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , k , a[500005] , sum[500005] , cnt , p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(ll i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(ll r = 1;r <= n;r++)
	{
		if(a[r] == k)
		{
			cnt++;
			p = r;
			continue;
		}
		for(ll l = p + 1;l < r;l++)
		{
			if((sum[r] ^ sum[l - 1]) == k)
			{			
				p = r;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
