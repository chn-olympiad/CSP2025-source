#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans,sum,f[5005];
long long jc(int x)
{
	int ps=0;
	for(int i=1;i<=x;i++)ps=(ps+i)%mod;
	return ps;
}
void qh(int x,int m,int k,int v)
{
	if(x==m){
		if(a[x]+v>k)sum++;
		if(v>k)sum++;return ;
	}
	if(v>k)sum++;
	for(int i=x;i<=m;i++)
	{
		qh(i+1,m,k,v);
		qh(i+1,m,k,v+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans=(ans+jc(n-i+1))%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		sum=0;
		qh(1,i-1,a[i],0);
		ans+=sum;
	}
	cout<<ans/2;
	return 0;
}
