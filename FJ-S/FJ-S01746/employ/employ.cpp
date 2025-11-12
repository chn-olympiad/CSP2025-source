#include<iostream>
#include<cstdio>
using namespace std;
#define mod 998244353
int n,m;
long long ans=0;
int c[505];
int s[505];
int bj[505];
string g;
void dfs(int now,int ly,int wly)
{
	if(now>n)
	{
		if(ly>=m)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!bj[i])
		{
			bj[i]=1;cout<<i<<" ";
			if(c[i]>wly&&g[now]=='1')
				dfs(now+1,ly+1,wly);
			else
				dfs(now+1,ly,wly+1);
			bj[i]=0;
			
		}
	}
}
int main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>g;
	for(int i=1;i<=n;i++)
	{
	    cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}    
  
  	