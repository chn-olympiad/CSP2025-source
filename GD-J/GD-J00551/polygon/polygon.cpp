#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5002],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int k=1;k<=n-i+1;k++)
		{
			int s=0,op=0;
			for(int j=k;j<=k+i-1;j++)
			{
				s+=a[j];
				op=k+i-1;
			}
			if(s>a[op]*2)
			ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
 } 
