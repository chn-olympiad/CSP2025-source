#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,a[5005],ans=0,b[5005],p[5005],f=0;
void dfs(long long l,long long w,long long ma,long long s)
{
	if(l>3)
	{
		if(ma==b[w]&&s>2*ma&&n!=w)  
		{
			ans=ans%mod+1,ans=(ans%mod)*p[n-w]%mod;
			return ;
		}
		if(s>2*ma) ans=ans%mod+1;
	}
	if(l>n)
		return ;
	for(int i=w+1;i<=n;i++)
		dfs(l+1,i,max(ma,a[i]),s+a[i]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);	
		if(a[i]!=1) f=1;
	}
	if(!f&&n>=500)
	{
		printf("%lld",p[n]-1-n*(n-2)%mod);
		return 0;
	}
	b[n+1]=0;
	for(int i=n;i>0;i--) b[i]=max(b[i+1],a[i]);
	dfs(1,0,0,0);
	printf("%lld",ans%mod);
} 
//10£º14 »¹ÊÇ¿Ê 
//11£º00 ºÃ¿Ê 
