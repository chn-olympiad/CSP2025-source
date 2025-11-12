#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5011];
int mi[5001];
int tot=0;
int pp=998244353;
int dp[5001][5001];
//int fastmi(int n,int i)
//{
//	int result=1;
//	while(i!=0)
//	{
//		if(i%2==1) result=((result%pp)*n)%pp;
//		n=((n%pp)*(n%pp))%pp;
//		i/=2;
//	}
//	return result;
//}
void dfs(int i,int mx,int ml)
{
	if(ml>mx)
	{
		tot=(tot+mi[i])%pp;
		return;
	}
	for(int j=i;j>=1;j--)
	{
		dfs(j-1,mx,ml+a[j]);
	}
}
int cal(int n,int p)
{
	int n1=1,n2=1,n3=1;
	for(int i=1;i<=n;i++) n1=(n1*i)%pp;
	for(int i=1;i<=p;i++) n2=(n2*i)%pp;
	for(int i=1;i<=n-p;i++) n3=(n3*i)%pp;
	return ((n1/n2)/n3)%pp;
}
signed main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int lll=1;
	for(int i=0;i<=5000;i++)
	{
		mi[i]=lll;
		lll=(lll*2)%pp;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
//	if(a[n]==1)
//	{
//		int res1=0;
//		for(int i=1;i<=(n-i);i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				dp[j][i]=i
//			}
//		}
//		cout<<res1;
//	}
//	else
//	{
	if(n<=500)
	{
		sort(a+1,a+n+1);
		for(int i=n;i>=3;i--)
		{
			dfs(i-1,a[i],0);
		}
		cout<<(tot%pp);
	}
	else cout<<0;
		
//	}
	
	return 0;
}