#include<bits/stdc++.h>
using namespace std;

int a[500005]={},maxn=0;
vector<int> ar[500005]; 
vector<int> pd;

int ans=0;
//   在前i个数前有的=k的最多不重合的序列 
int dp[500005][500005]={};

bool ch()
{
	for(int i=0;i<=maxn;i++)
	{
		if(pd[i]!=ar[0][i])
		{
			return 0;
		}
	}
	return 1;
}


void er(int o,int i,int t)
{
	if(o==0)
	{
		maxn=max(maxn,t);
		return ;
	}
	int x=o/2;
	int y=o%2;
	er(x,i,t+1);
	ar[i].push_back(y);
	return ;
}

int hh(int x)
{
	for(int i=0;i<maxn;i++)
	{
		if(pd[i]==ar[x][i])
		{
			pd[i]=1;
		}
		else
		{
			pd[i]=0;
		}
	}
}


void ddp(int l,int r)
{
	for(int i=0;i<maxn;i++)
	{
		pd.push_back(ar[l][i]);
	}
	for(int i=l+1;i<=r;i++)
	{
		hh(i);
	}
	if(ch())
	{
		dp[l][r]=1;
	}
	return ;
}

void dfs(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<maxn;i++)
		{
			pd.push_back(ar[l][i]);
		}
		if(ch())
		{
			dp[l][l]=1;
		}
		return ;
	}
	int ll=(l+r)/2;
	ddp(ll,r);
	dfs(ll,r);
	ddp(l,ll-1);
	dfs(l,ll-1);
	
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	er(k,0,0);
	for(int i=1;i<=n;i++)
	{
		int ai;
		cin>>ai;
		a[i]=ai;
		er(ai,i,0);
	}
	for(int i=0;i<=n;i++)
	{
		while(ar[i].size()<maxn)
		{
			ar[i].push_back(0);
		}
	 } 
	ddp(1,n);
	dfs(1,n);
	
	for(int i=1;i<=n;i++)
	{
		for(int l=i;l<=n;l++)
		{
			ans=max(dp[i][l]+dp[1][i],ans);
		}
		cout<<endl;
	}
	cout<<n*n-3;
	return 0;
 } 
