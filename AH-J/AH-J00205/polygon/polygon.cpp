#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],f[5005],s[5005],t[50005];
bool check()
{
	for(long long i=1;i<=n;i++)
		if(a[i]!=1)
			return 0;
	return 1;
}
void work1()
{
	f[0]=f[2]=0,s[1]=0,s[2]=1;
	for(long long i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+s[i-1])%MOD;
		s[i]=(2*s[i-1]+i-1)%MOD;
	}
	cout<<f[n]<<endl;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(check())
	{
		work1();
		return 0;
	}
	t[0]=1;
	for(long long i=1;i<=n;i++)
	{
		long long s=0;
		for(long long j=1;j<=50000;j++)
			if(j>a[i])
				s=(s+t[j])%MOD;
		f[i]=(f[i-1]+s)%MOD;
		for(long long j=50000-a[i];j>=0;j--)
			t[j+a[i]]=(t[j+a[i]]+t[j])%MOD;
	}
	cout<<f[n]<<endl;
	return 0;
}
