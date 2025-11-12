#include <bits/stdc++.h>
#define ll long long
const int mod=998244353;
using namespace std;
ll n,a[5005],maxn,sum[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		if((x+y>z&&x+z>y)&&z+y>x)
		{
			cout<<"1";
			return 0;
		}
	    else
	    {
	    	cout<<"0";
	    	return 0;
		}
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	    sum[i]=sum[i-1]+a[i];
	for(int k=2;k<=n-1;k++)
	{
		for(int i=1;i<=n;i++)
		    for(int j=i+k;j<=n;j++)
		    {
			    if(sum[j]-sum[i-1]>2*a[j])
			    {
			    	ans++;
			    	//cout<<i<<" "<<j<<'\n';
				}    
	 	    }
	}
	cout<<ans%mod;
}

