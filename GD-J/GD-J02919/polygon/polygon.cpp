#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll n,a[5005],ans;
void dfs(int step,ll nowsum,ll nmax,int stk)
{
	if(step>n)
	{
		if(nowsum>2*nmax&&stk>=3)
		{
			ans++;
			if(ans>=MOD) ans%=MOD; 
		}
		return ;
	}
	dfs(step+1,nowsum,nmax,stk);
	dfs(step+1,nowsum+a[step],max(nmax,a[step]),stk+1);
}
void slove1()
{
	if(n<=26) 
	{
		dfs(0,0,-1,0);
		cout<<ans/2;
	}
	else
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				x++;
			}
		}
		int k=6;
		int v=x*(x-1)*(x-2)/k,ans;
		for(int i=3;i<=n-1;i++)
		{
			ans+=(v/k);
			k*=(i+1);
			v=v*(n-i);
			ans%=MOD;
			v%=MOD;
		}
		cout<<ans;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	slove1();
	return 0;
}

