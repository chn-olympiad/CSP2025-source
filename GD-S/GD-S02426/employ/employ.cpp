#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstdio>
using namespace std;
#define mod 998244353
int a[1000000];
int c[1000000];
int vis[1000000];
int n,m;
long long ans=0;
void dfs(int k,int t)//t: out
{
//	cout<<k<<" "<<t<<endl;
	if(k==n+1&&n-t>=m)
	{
		ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
	//	cout<<"/ ";
		if(c[i]<=t)
		{
			dfs(k+1,t+1);
		}
	//	cout<<"//"<<endl;
		
	//	cout<<i<<":";
	//	cout<<k<<" "<<t<<" "<<i<<endl;
		if(a[k]==1)
		dfs(k+1,t);
		else dfs(k+1,t+1);
		vis[i]=0;
	}
	return ;
}
string cn;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int flag=0;
	cin>>n>>m;
//	char lx;
	cin>>cn;
	cn='0'+cn;
	for(int i=1;i<=n;i++)
	{
		if(cn[i]=='1')
		a[i]=1;
		else a[i]=0,flag=1;
	}
	int sm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(flag==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod; 
		}
		cout<<ans;
		return 0; 
	}
	
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
111
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
