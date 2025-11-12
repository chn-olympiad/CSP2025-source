#include<iostream>
using namespace std;
const int M=998244353;
int a[5010],n,c[5010][5010];
int dfs(int x,int mx,int s)
{
	if(x>n)
	{
		if(2*mx<s)return 1;
		else return 0;
	}
	return (dfs(x+1,mx,s)+dfs(x+1,max(mx,a[x]),s+a[x]))%M;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int oi=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1)oi=0;
	}
	if(n<=20)
	{
		cout<<(dfs(0,0,0)/2)%M;
		return 0;
	}
	if(oi==1)
	{
		for(int i=0;i<=n;i++)
		{
			c[i][0]=1;
			for(int j=1;j<=i;j++)
				c[i][j]=(c[i-1][j]%M+c[i-1][j-1]%M)%M;
		}
		int ans=0;
		for(int i=3;i<=n;i++)
			ans=(ans+c[n][i]%M)%M;
		cout<<ans;
		return 0;
	}
}
