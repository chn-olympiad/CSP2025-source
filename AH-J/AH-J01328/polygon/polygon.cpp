#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,sum=0,a[5005],c[5005],qc[5005],s=0,flag=1;
void dfs(int x,int i,int s,int maxn)
{
	if(i==n+1)
	{
		if(x<3) return ;
		if(s>2*maxn) sum=(sum+1)%mod;
		return ;
	}
	dfs(x+1,i+1,s+a[i],max(maxn,a[i]));
	dfs(x,i+1,s,maxn);
}
void dfs2(int maxn,int step,int x,int s)
{
	if(x>=3&&s>maxn)
	{
		sum=(sum+1+(1+step)%mod*step%mod/2)%mod;
		return ;
	}
	if(step==0) return ;
	dfs2(maxn,step-1,x+1,s+a[step]);
	dfs2(maxn,step-1,x,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i==1) s=a[i];
		else if(a[i]!=s) flag=0;
	}
	if(flag)
	{
		qc[0]=1;
		qc[1]=1;
		for(int i=2;i<=n;i++)
			qc[i]=qc[i-1]*i%mod;
		for(int i=3;i<=n;i++)
			sum=(sum+qc[n]/qc[i]/qc[n-i])%mod;
		cout<<sum;
		return 0;
	}
	if(n<=28)
	{
		dfs(0,1,0,0);
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
		c[i]=(c[i-1]+a[i])%mod;
	for(int i=n;i>=1;i--)
	{
		if(a[i]>=c[i-1]) continue;
		dfs2(a[i],i-1,1,0);
	}
	cout<<sum%mod;
	return 0;
}
