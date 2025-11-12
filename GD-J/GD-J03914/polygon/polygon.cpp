#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5050];
bool kp(long long a,long long b)
{
	return a<b;
}
void dfs(long long loc,long long cnt,long long sum,long long maxn)
{
	if(loc>n)
	{
		return;
	}
	sum+=a[loc];
	maxn=a[loc];
	if(sum>2*maxn && cnt>=3)
	{
		ans=ans%998244353+1;
	}
	for(long long i=loc+1; i<=n; i++)
	{
		dfs(i,cnt+1,sum,maxn);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(long long i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n,kp);
	
	for(long long i=1; i<=n-2; i++)
	{
		dfs(i,1,0,-1);
	}
	
	cout<<ans%998244353;
	return 0;
	
}
