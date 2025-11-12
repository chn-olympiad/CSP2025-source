#include<bits/stdc++.h>
using namespace std;
int n;
long long  a[5005];
long long p[5005];
int mx;
long long ans;
const long long mod=998244353;
void dfs(int x,int sum,int m,int ci)
{
	if(sum-a[x]<=mx||ci<2)
	{
		return ;
	}
	ans++;
	ans%=mod;
	sum-=a[x];
	for(int i=x+1;i<m;i++)
	{
		dfs(i,sum,m,ci--);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--)
	{
		mx=a[i];
		dfs(0,p[i-1],i,i);
	}
	cout<<ans<<endl;
	return 0;
}

