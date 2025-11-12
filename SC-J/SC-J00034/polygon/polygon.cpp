#include<bits/stdc++.h>
using namespace std;
int x[100],n,ans,mod=998244353;
bool sg;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int id,int maxn,int sum,int sl)
{
	if((sum>maxn*2)&&sl>=3)ans=(ans+1)%mod;
	if(id>=n)return;
	for(int i=id+1;i<=n;i++)
	{
		dfs(i,maxn,sum+x[i],sl+1);
	}
}
int jc(int n)
{
	if(n==0)return 1;
	else return n%mod*jc(n-1)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]!=1)sg==true;
	}
	if(!sg)sort(x+1,x+n+1,cmp);
	sort(x+1,x+n+1,cmp);
	if(!sg)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,x[i],x[i],1);
		}
	}
	else
	{
		for(int i=1;i<=n-2;i++)
		{
			ans=ans+jc(n)/jc(n-i);
		}
	}
	cout<<ans%mod;
	return 0;
 } 