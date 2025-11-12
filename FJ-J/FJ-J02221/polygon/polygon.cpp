#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],su[5010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) su[i]=su[i-1]+a[i];
	if(su[n]<=2*a[n])
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if(su[j]-su[i-1]>2*a[j])
			{
				ans=(ans+1)%mod;
				for(int l=i+1;l<j;l++)
				{
					for(int r=l;r<j;r++)
					{
						if(su[j]-su[i-1]-(su[r]-su[l-1])>2*a[j]) ans=(ans+1)%mod;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
