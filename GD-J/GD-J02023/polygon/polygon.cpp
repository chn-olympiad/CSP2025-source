#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=3e6+10;
const int M=998244353;
const int inf=0x3f3f3f3f;
ll n,a[N]; 
ll k;
ll ans;
void dfs(int step,ll sum,ll maxx,int last)
{
	if(step==0)
	{
		if(sum>2*maxx)
		{
			ans++;
			ans%=M;
		}
		return;
	}
	for(int i=last;i<=n;i++)
	{
		dfs(step-1,sum+a[i],max(maxx,a[i]),i+1);
	}
}
ll jc(int x)
{
	ll ans=1;
	for(int i=2;i<=x;i++)
	{
		ans*=i;
	}
	return ans;
}
ll C(int x,int y)
{
	ll sum=jc(y);
	ll summ=jc(x)*jc(y-x);
	sum/=summ;
	sum%=M;
	return sum;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k=max(k,a[i]);
	}
	if(n<=20)
	{
		ans=0;
		for(int i=3;i<=n;i++)
		{
			dfs(i,0,0,1);
		}
		printf("%lld",ans);
		return 0;
	}
	if(k==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(i,n);
			ans%=M; 
		}
		k=ans;
		printf("%lld",k);
		return 0;
	}
 	return 0;
}
