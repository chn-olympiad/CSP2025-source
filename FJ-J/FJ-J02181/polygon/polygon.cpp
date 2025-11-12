#include<bits/stdc++.h>
using namespace std;
int n,a[1000020],ans,l;
long long mod=998244353;
void dfs(int ii,int k,int sum,int en)
{
	if(k>l)
	{
		if(sum>en*2)ans++;
		return;
	}
	for(int i=ii;i<=n;i++)
	{
		if(k==l&&sum+a[i]<a[i]*2)break;
		else 
		dfs(i+1,k+1,sum+a[i],a[i]);
	}
	return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		l=i;
		dfs(1,1,0,0);
	}
	cout<<ans%mod;
	return 0;	
} 
