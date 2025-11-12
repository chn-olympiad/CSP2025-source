#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5000005],sum[5000005],dp[5000005],s[5000005],e[5000005],c[5000005];
pair<int,int> ed[5000005];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
int xo(int x,int y)
{
	int z=0,tt=1;
	while(x||y)
	{
		int xx=x%2,yy=y%2,zz;
		if(xx==yy)  zz=0;
		else  zz=1;
		zz*=tt;
		tt*=2;
		z+=zz;
		x/=2,y/=2;
	}
	return z;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	bool f=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1){f=0;break;}
		else  cnt++;
	}
	if(f)
	{
		if(m==1)  cout<<cnt;
		else  cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)  sum[i]=xo(sum[i-1],a[i]);      
	int t=0;
	for(int i=1;i<=n;i++)
	{
		int x=xo(m,sum[i]);
		int st=lower_bound(sum+1,sum+i,x)-sum,en=upper_bound(sum+1,sum+i,x)-sum-1;
		if(a[i]==m)  ed[++t]=make_pair(i,i);
		if(sum[i]==m)  ed[++t]=make_pair(1,i);
		if(st>n||en>n)  continue;
		for(int j=st;j<=en;j++)
			if(xo(sum[i],sum[j]))  ed[++t]=make_pair(j+1,i);
	}
	sort(ed+1,ed+t+1,cmp);
	int ans=0;
	for(int i=1;i<=t;i++)
	{
		s[i]=ed[i].first,e[i]=ed[i].second;
		//cout<<s[i]<<" "<<e[i]<<"\n";
	}
	for(int i=1;i<=t;i++)
	{
		int x=lower_bound(e+1,e+i,s[i])-e-1;
		if(x<=t){if(e[x]<s[i])  dp[i]=max(ans,c[x]+1);}
		else  dp[i]=1;
		c[i]=max(c[i-1],dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
