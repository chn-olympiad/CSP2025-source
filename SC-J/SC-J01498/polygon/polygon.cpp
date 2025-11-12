#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],ans,n,sum=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[j]>2*a[j])
				ans++;
			ans%=sum;
		}
	}
	
	cout<<ans;
	return 0;
}