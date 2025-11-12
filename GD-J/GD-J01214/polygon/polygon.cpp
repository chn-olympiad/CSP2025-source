#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long mod=998244353,ans,c[10005],b[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int m=a[n]*2+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=m;j++)
		{
			ans+=c[j];
			ans%=mod;
		}
		for(int j=1;j<=m;j++) b[j]=0;
		b[a[i]]++;
		b[a[i]]%=mod;
		for(int j=1;j<=m;j++)
		{
			b[min(m,j+a[i])]+=c[j];
			b[min(m,j+a[i])]%=mod;
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
			c[j]%=mod;
		}
	}
	cout<<ans;
	return 0;
}
