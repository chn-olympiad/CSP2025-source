#include<bits/stdc++.h>
using namespace std;
const int MM=998244353;
int n;
int a[1000010];
int b[1000010];
bool c[1000010];
long long ans;
long long res;
int maxn;
int k=0;
int jilu;
int man;
void dfs(int x,int u,int jilu)
{
	if(x==u)
	{
		res=0;
		maxn=0;
		for(int i=1;i<=u;i++)
		{
			res+=b[i]%MM;
			maxn=max(maxn,b[i]);
		}
		if(res>maxn*2)
		{
			ans++;
		}
		return;
	}
	for(int i=k+1;i<=n;i++)
	{
		if(c[i]!=true)
		{
			c[i]=true;
			b[x+1]=a[i];
			man=k;
			k=i;
			dfs(x+1,u,man);
			k=jilu;
			c[i]=false;
		}
	}
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
	for(int i=3;i<=n;i++)
	{
		dfs(0,i,0);
	}
	cout<<ans;
}