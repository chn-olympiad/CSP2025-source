#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int d[N],a[N],pd[N],ans,n,m;
void dfs(int x,int t,int u)
{
	if(x>n)
	{
		if(t>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!pd[i])
		{
			pd[i]=true;
			if(d[i]==0) dfs(x+1,t,u+1);
			else
			{
				if(u>=a[i]) dfs(x+1,t,u+1);
				else dfs(x+1,t+1,u);
			}
			pd[i]=false;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		d[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
// Ren5Jie4Di4Ling5%
