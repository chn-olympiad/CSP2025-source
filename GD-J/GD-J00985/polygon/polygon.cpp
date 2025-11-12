#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[50005];
long long f[50005];
void work(long long k,long long zd,long long t,long long p)
{
	if(k>n)
	{
		if(t>zd*2)ans=(ans+p)%998244353;
		return;
	}
	long long o=1;
	for(int i=1;i<=f[a[k]];i++)
	{
		o=(o*(f[a[k]]-i+1)/i)%998244353;
		work(k+1,max(zd,a[k]),t+a[k]*i,(p*o)%998244353);
	}
	work(k+1,zd,t,p);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(!f[a[i]])f[a[i]]++;
		else f[a[i]]++,i--,n--;
	}
	work(1,0,0,1);
	cout<<ans;
	return 0;
}
