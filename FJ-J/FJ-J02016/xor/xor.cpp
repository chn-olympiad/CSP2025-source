#include<iostream>
#include<cstdio>
using namespace std;
long long a[500005];
int f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			if(abs(a[i]-a[j-1])==k)
				f[i]=max(f[i],f[j-1]+1);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}