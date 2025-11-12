#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum=1,ans=0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		sum
		if(i==m)
		{
			ans+=sum;
		}
	}
	ans+=sum;
	cout<<ans%998244353;
	return 0;
}
