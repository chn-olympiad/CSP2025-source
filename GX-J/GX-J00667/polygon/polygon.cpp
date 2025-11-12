#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[5010],f[5010],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	f[0]=0;
	for(long long i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		cout<<f[i]<<endl;
	}
	for(long long i=n;i>=3;i--)
	{
		long long num=max(a[i],max(a[i-1],a[i-2]));
		for(long long j=i-2;j>=1;j--)
		{
			num=max(num,a[j]);
			cout<<num*2<<" "<<f[i]-f[j-1]<<" "<<endl;
			if(f[i]-f[j-1]>num*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
