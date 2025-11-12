#include<bits/stdc++.h>
using namespace std;
long long b[10005];
long long a[50010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
long long n,i,j;
long long ans=0;
cin>>n;
for(i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+n+1); 
for(i=1;i<=n;i++)
{
	for(j=5001;j>=1;j--)
	{
		if(j>a[i])
		{
			ans=(ans+b[j])%998244353;
		}
		else
		break;
	}
	for(j=5001;j>=1;j--)
	{
		if(j+a[i]>5000)
		{
			b[5001]=(b[j]+b[5001])%998244353;
		}
		else
		{
			b[j+a[i]]=(b[j]+b[j+a[i]])%998244353;
		}
	}
	b[a[i]]=(b[a[i]]+1)%998244353;
}
cout<<ans%998244353;
}




