#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1,POP=998244353;
long long n,m,sum,a[N],b[N],x[N],po[N];
bool ok(int p)
{
	long long oko=0;
	for(int i=1;i<p;i++)
		oko+=x[i];
	for(int i=1;i<=m;i++)
		if(oko==po[i])
			return false;
	po[++m]=oko;
	return true;
}
int dfs(int p)
{
	if(p>3&&ok(p))
	{
		long long ans=0,jok=0;
		for(int i=1;i<p;i++)
		{
			jok=max(jok,x[i]);
			ans+=x[i];
		}
		if(ans>2*jok)sum=(sum+1)%POP;
	}
	for(int i=p;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			x[p]=a[i];
			dfs(p+1);
			b[i]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=3)
	{
		if(n!=3)
		{
			cout<<0;
			return 0;
		}
		long long s1=0,s2=0; 
		for(int i=1;i<=n;i++)
		{
			s1+=a[i];
			s2=max(s2,a[i]);
		}
		if(s1>s2*2)
			cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	if(a[n]==1&&a[1]==1)
	{
		 long long pk[100001];
		 memset(pk,0,sizeof(pk));
		 pk[4]=1;
		 pk[5]=5;
		 pk[6]=13;
		 for(int i=7;i<=n;i++)
		 	pk[i]=pk[i-1]+i;
		cout<<pk[n]%POP;
		return 0;
		
	}
	dfs(1);
	cout<<sum%POP;
	return 0;
} 
