#include<bits/stdc++.h>
using namespace std;
int n,c[20],m;
bool b[20];
string s;
long long ans=0;
void dfs(int i,int h)
{
	if(i==n+1) 
	{
		if(n-h>=m) 
		{
			if(ans==998244353) ans=0;
			ans++;
		}
		return ;
	}
	for(int j=1;j<=n;j++)
	{
		if(!b[j])
		{
			b[j]=1;
			if(h>=c[j]||!(s[i-1]-'0')) dfs(i+1,h+1);
			else dfs(i+1,h);
			b[j]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
		cin>>m;
		cin>>s;
		for(int i=1;i<=n;i++) cin>>c[i];
		dfs(1,0);
	}
	else
	{
		cin>>s;
		for(int i=1;i<=n;i++)
		{
			if(s[i]-'0')
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
	}
	
	cout<<ans;	
	return 0;
}

