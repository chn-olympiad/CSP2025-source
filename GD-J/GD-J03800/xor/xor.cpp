#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k,a[500005],f[500005],sl,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		f[i] = f[i-1] ^ a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = sl;j < i;j++)
		{
			if((f[i] ^ f[j]) == k)
			{
				ans++;
				sl = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
