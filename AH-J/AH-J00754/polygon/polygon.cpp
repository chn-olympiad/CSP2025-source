#include <bits/stdc++.h>
using namespace std;
long long n,sy=0;
long long MOD=998244353;
int a[1001];
bool b[1001];
long long dp[5010];
long long calc[5010];
void dfs(int start,int t,int pp)
{
	if (t==pp)
	{
		long long num=0,nmax=0;
		for (int i=1;i<=n;i++)
		    if (b[i]==1) 
		    {
				if (nmax<a[i]) nmax=a[i];
				num+=a[i];
			}
		if (num>2*nmax)
		{
			sy++;
		    sy%=MOD;
		}
		    return;
	}

	for (int i=start;i<=n;i++)
	{
		if (b[i]==0)
		{
			b[i]=1;
			dfs(i+1,t+1,pp);
			b[i]=0;
		}
	}
		
}
void calcn()
{
	calc[1]=1;
	for (int i=2;i<=5010;i++)
	    calc[i]=(calc[i-1]+i)%MOD;
}
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	    cin>>a[i];
	if (n<3) 
	{
		cout<<0;
		return 0;
	}
	if (n==3)
	{
		int p=0,nmax=0;
		for (int i=1;i<=n;i++)
		{
			p+=a[i];
			if (a[i]>nmax) nmax=a[i];
		}   
		 if (p>2*nmax) cout<<1;
		 else cout<<0;
		 return 0;
	}
	int nmax=0;
	for (int i=1;i<=n;i++)
	    if (a[i]>nmax) nmax=a[i];
	if (nmax==1)
	{
		calcn();
		dp[3]=1;
		for (int i=4;i<=n;i++)
		    dp[i]=(dp[i-1]+calc[i-2])%MOD;
		cout<<dp[n];
		return 0;
	}
	for (int i=3;i<=n;i++)
	{
		dfs(1,0,i);
	}
	    
	cout<<sy;
	return 0;
}
