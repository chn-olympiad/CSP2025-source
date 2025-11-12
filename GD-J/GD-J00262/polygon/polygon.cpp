#include<bits/stdc++.h>
using namespace std;
long long int n,a[10000001],sum,ans=0,j=0,k=0,f,f1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				f=f+a[k]+a[i]+a[j];
				if(f>2*a[k])
				{
					ans++;
				}
			}
		}
	}
	cout<<(ans%998244353); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
