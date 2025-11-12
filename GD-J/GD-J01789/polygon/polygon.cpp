#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 5010

int n,a[N],ans=0;
void dfs(int id,int sum,int x)//上一个的下标，总和，已选的个数 
{
	if(sum>2*a[id])
	{
		ans++;ans%=mod;
	}
	for(int i=id+1;i<=n;i++)
	{
		dfs(i,sum+a[i],x+1);
	}
}

int C[N][N];
void init()
{
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
//	freopen("hello.txt","r",stdin);
	
	cin>>n;
	int mxai=0;
	for(int i=1;i<=n;i++)cin>>a[i],mxai=max(mxai,a[i]);
	sort(a+1,a+n+1);
	
	if(mxai>1)
	{
		dfs(0,0,0);
		cout<<ans;
	}
	else
	{
		init();
		for(int i=3;i<=n;i++)ans=(ans+C[n][i])%mod;
		cout<<ans;
	}
	
	return 0;
}
/*
5
1 2 3 4 5

*/
