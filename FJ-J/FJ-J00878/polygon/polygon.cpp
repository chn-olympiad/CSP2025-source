#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],sum,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum=a[i];
		for (int j=i+1;j<=n;j++)
		{
			if(j-i>=3)
			{
				if(sum>a[j]*2)
				{
				    ans++;
				    ans=ans%MOD;
			    }
			}
			sum+=a[j];
		}
	}
	cout<<ans;
	return 0;
}
