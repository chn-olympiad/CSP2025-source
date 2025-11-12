#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
using namespace std;

const int N=1e6+5;
const int mod=998244353;

int a[N];
int n,ans;
long long dp[N],pfx[N];
//long long f[509][509];//小于r+1的区间个数 

void dfs(int k,long long sum,int nc,int maxn)
{
	if(k>n)
	{
		if(nc>=3&&sum>2*maxn)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	//if(a[k+1]<sum&&k>3)
	
	dfs(k+1,sum+a[k],nc+1,max(maxn,a[k]));
	
	//if(sum>a[k+2])
	
	dfs(k+1,sum,nc,maxn);
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,-1);
	cout<<ans;
	return 0;
}
/*
int main()
{
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pfx[i]=pfx[i-1]+a[i];
	}
	
	for(int l=1;l<n-1;l++)
	{
		for(int r=l+1;r<n;r++)
		{
			printf("%d and %d\n",pfx[r]-pfx[l-1],a[r+1]);//
			if(pfx[r]-pfx[l-1]<a[r+1])
			{
				f[l][r]=(f[l][r-1]+1)%mod;
				cout<<"++"; //
			}
		}
	}
	
	dp[0]=dp[1]=dp[2]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=pfx[i-1])
		{
			dp[i]=dp[i-1];
		}
		else
		{
			int temp=0;
			for(int j=2;j<i;j++)
			{
				temp=(temp+f[j][i-1])%mod;
				cout<<f[j][i-1]<<endl;
			}
			dp[i]=(dp[i-1]+temp)%mod;	
		}
		cout<<pfx[i]<<" "<<dp[i]<<endl;//
	}
	cout<<endl;//
	cout<<dp[n];
	return 0;
}*/


/////////////////////////////////////////////////////////////////////////////////
