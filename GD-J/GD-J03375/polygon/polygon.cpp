#include<bits/stdc++.h>
using namespace std;
int l[5010],arr[5010],n;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];
	}
	if(n < 3) cout << 0;
	else if(n == 3) 
	{
		int sum = 0, Max = 0;
		for(int i=1;i<=n;i++)
		{
			sum += l[i];
			Max = max(Max,l[i]);
		}
		if(sum > 2*Max) cout << 1;
		else cout << 0;
	}
	else
	{
		for(int i = n-2;i>=1;i--) ans+=i;
		cout << ans%998244353;
	}
	return 0;
}
