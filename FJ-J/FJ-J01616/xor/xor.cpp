#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005],vis[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	if(k<=1)
	{
		long long zero=0,one=0;
		for(int i = 1;i<=n;i++)
		{
			if(a[i] == 0) zero++;
			else one++;
		}
		cout<<max(one,zero);
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		long long dwrg = a[i];
		for(int j = i;j<=n;j++)
		{
			if(a[j] == k && !vis[j])
			{
				vis[j] = true;
				ans++;
			}else if((dwrg ^ a[j+1]) == k && !vis[j])
			{
				dwrg ^= a[j];
				i=j+1;
				vis[j] = true;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
