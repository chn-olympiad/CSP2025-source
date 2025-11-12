#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int a[N],sum[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if(sum[j]-sum[i-1]>2*a[j])cnt++;
			cnt%=mod;
		}
	}
	cout<<cnt;
	return 0;	
} 
