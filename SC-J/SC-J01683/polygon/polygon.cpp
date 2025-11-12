#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans=0,b[5005];
void f(int i,int h,int zd,int gs=0)
{
	if(h>2*zd&&gs>=3)	ans++;
	for(int j=i+1;j<=n;j++)
		f(j,h+a[j],max(zd,a[j]),gs+1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)	m=0;
	} 
	if(n>20&&m==1)
	{
		b[0]=1;
		for(int i=1;i<=n;i++)	b[i]=(b[i-1]*i)%998244353;
		for(int i=3;i<=n;i++)
			ans+=(b[n]/b[n-i]/b[i])%998244353;
		cout<<ans%998244353;
		return 0;
	}
	f(0,0,0,0);
	cout<<ans%998244353;
	return 0;
} 