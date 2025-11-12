#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long ans;
const int N=10000,mod=998244353;
int a[5001],t[5001],w[5001],qzh[5001];
bool potato(int x,int y)
{
	return x>y;
}
long long dfs(int k,int sum,int maxx)
{
	if(2*maxx<sum)
	{
		//cout<<a[k]<<" "<<maxx<<":"<<int(pow(2,n-k))%998244353<<endl;
		return int(pow(2,n-k))%mod;
	}
	int s=0;
	
	for(int i=k+1;i<=n;i++)
	{
		if(k==0) maxx=a[i];
		s+=dfs(i,sum+a[i],maxx);
		s%=mod;
	}
	return s;
}
long long poww(int n,int k)
{
	long long s=1;
	for(int i=1;i<=k;i++)
	{
		s*=n;
		s%=mod;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0)
	{
		cout<<((n*(n-1)*(n-2))%mod+poww(2,n-3))%mod;
		return 0;
	}
	sort(a+1,a+n+1,potato);
	cout<<dfs(0,0,0);
	return 0;
}