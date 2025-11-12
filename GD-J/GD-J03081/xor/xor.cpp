#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		int cnt = a[i];
		if(cnt == k)
		{
			ans ++;
			continue;
		}
		for(int j = i + 1;j<=n;j++)
		{
			cnt ^= a[j]; 
			if(cnt == k)
			{
				i = j;
				ans ++;
				break;
			}
		}
		s2:;
	}
	cout<<ans<<"\n";
	return 0;
}
