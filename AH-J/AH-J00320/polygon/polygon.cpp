#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],qi[5005],s=0,mod=998244353,f=0,sh=1,xi=1;
void dfs(long long he,long long ma,long long ge,long long x)
{
	if(ge>=3&&he>ma*2)
	{
		s++;
		s%=mod;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(he+a[i],max(ma,a[i]),ge+1,i);
	}
	return ;
}
int main()
{
  freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	if(f==0)
	{
		sh=n*(n-1)*(n-2);
		xi=1*2*3;
		for(int i=3;i<=n;i++)
		{
			s=((s%mod)+(sh/xi)%mod)%mod;
			sh=(sh*(n-i))%mod;
			xi=(xi*(i+1))%mod;
		}
		cout<<s;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<s;
	return 0;
}
