#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=3,l,sum=0,ans=0,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			k=1;
			l=j;
			while(m)
			{
				sum=a[i]+a[l]+a[l+k];
				m--;
				k++;
			}
			if(sum>=2*a[l+k])
			{
				ans++;
				continue;
			}
		}
		if(m<=n)
		{
			m++;
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
