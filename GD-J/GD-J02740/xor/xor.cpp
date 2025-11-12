#include<bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans, x, t;


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(k == a[1])
	{
		ans++;
		t = 1;
	}
	for(int i = 2; i <= n; i++)
	{
		
		if(a[i] == k)
			{
				t = i;
				ans++;	
				continue;
			}
		x = a[i];
		for(int j = i - 1; j > t; j--)
		{
			x = x ^ a[j];
			if(x == k)
			{
				t = i;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
