#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510]={0},b[30]={0};
long long ans=0;
int dfs(int i,int x,int y){
	if(x>=m)
	{
		long long sum=1;
		for(int j=i;j<=n;j++)
		{
			sum=(sum*(j-i+1))%998244353;
		}
		ans+=sum;
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		if(b[j]==0)
		{
			b[j]=1;
			if(a[j]>y&&s[i-1]=='1')
			{
				dfs(i+1,x+1,y);
			}
			else
			{
				dfs(i+1,x,y+1);
			}
			b[j]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int x=1;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]=='0')
		{
			x=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(x)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	else if(n==m)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
