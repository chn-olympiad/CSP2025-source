#include<bits/stdc++.h>
using namespace std;
long long n,x[5005],book[5005],q[5005],ans;
bool speA=1;
const long long MOD=998244353;
void dfs(long long k,long long p)
{
	if(k>p)
	{
		long long maxx=-1,sum=0;
		for(long long i=1;i<=p;i++)
		{
			maxx=max(maxx,x[q[i]]);
			sum+=x[q[i]];
		}
		if(sum>2*maxx)
		ans++;
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(book[i]==0&&i>=q[k-1])
		{
			q[k]=i;
			book[i]=1;
			dfs(k+1,p);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]!=1)
		speA=0;
	}
	if(speA)
	{
		ans=1;
		for(long long i=1;i<=n-1;i++)
		{
			ans*=2;
			ans%=MOD;
		}
		cout<<ans;
	}
	else
	{
		sort(x+1,x+n+1);
		for(long long i=3;i<=n;i++)
		{
			dfs(1,i);
		}
		cout<<ans;
	} 
	return 0;
}

