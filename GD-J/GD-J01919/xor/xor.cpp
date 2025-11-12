#include<bits/stdc++.h>
using namespace std;
int f[500005],a[500005],sum[500005],pre[2000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	memset(pre,-1,sizeof pre);
	pre[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		if(pre[k ^ sum[i]] >= 0)
		{
			f[i] = max(f[i],f[pre[k ^ sum[i]]] + 1);
		}
		pre[sum[i]] = i;
	}
	cout << f[n];
	return 0;
}
