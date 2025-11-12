#include<bits/stdc++.h>
using namespace std;
int a[505];
const int M=998244353;
long long c[505][505];
long long cj[505];
bool vis[505];
int e[505];
int n,m;
string s;
int g[100];
int ans=0;
void dfs(int p,int lu,int mei)
{
	if(lu+e[p]<m)return ;
	if(p==n+1)
	{
		if(lu>=m)
		{
			ans++;
			for(int i=1;i<=n;i++)cout<<g[i]<<" ";
			cout<<'\n';
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(mei>=a[i])
			{
				dfs(p+1,lu,mei+1);
				continue;
			}
			if(s[i-1]=='1')
			{
				vis[i]=1;
				g[p]=i;
				dfs(p+1,lu+1,mei);
				vis[i]=0;
			}
			else 
			{
				g[p]=i;
				vis[i]=1;
				dfs(p+1,lu,mei+1);
				vis[i]=0;
			}
		}
	}
}
void f(){
	c[1][1]=1;
	for(int i=2;i<=501;i++)
	{
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]%M+c[i-1][j-1]%M)%M;
		}
	}
	cj[1]=1;
	for(int i=2;i<=501;i++)
	{
		cj[i]=(cj[i-1]%M*i%M)%M;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	f();
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ok=1;
	int oe=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]!='1')ok=0;
		else oe++;
	}
	for(int i=n;i>=1;i--)
	{
		e[i]=e[i+1]+(s[i-1]-'0');
	}
	if(ok)
	{
		cout<<cj[n]%M;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%M-1;
	return 0;
}
/*
3 2
101
1 1 2
*/
