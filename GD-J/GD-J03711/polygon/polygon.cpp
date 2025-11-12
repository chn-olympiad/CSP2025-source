#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,a[5001],m,sum,l,r,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l=1;
	r=2;
	while(l<=n-2)
	{
		for(int j=r+1;j<=n;j++)
		{
			for(int i=1;i<=n-2;i++)
			{
				m=max(a[l],a[r]);
		        sum=a[l]+a[r];
				if(i+j-1<=5)
				{
					for(int z=j;z<=i+j-1;z++)
				    {
					    m=max(m,a[z]);
					    sum+=a[z]; 
				    }
				}    
				if(sum>(m+m))
				{
					ans++;
				}
			}
		}
		r++;
		if(r>n)
		{
			l++;
			r=l+1;
		} 
	}
	cout<<ans%mod;
}
