#include <bits/stdc++.h>
using namespace std;
long long n,k,a[10000005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		for(long long i = 1;i <= n;i++)
		{
			if(i != n && a[i] == a[i + 1])
			{
				ans++;
				i++; 
			}
			else if(a[i] == 0)
			{
				ans++;
			} 
		}
		cout << ans;
		return 0;
	}
	return 0;
}
