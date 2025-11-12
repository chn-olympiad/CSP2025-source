#include<bits/stdc++.h>
using namespace std;

int n,m,c[505],ans=0,a[505];
bool v[505];
string s;

void dfs(int x,int sum)
{
	if(x==n+1)
	{
		if(sum>=m)
		{
		  ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==1)
		  continue;
		v[i]=1;
		a[x]=i;
		if((x-sum-1)<c[i])
		{
			if(s[x-1]=='1')
			  dfs(x+1,sum+1);
			else
			  dfs(x+1,sum);
		}
		else
		  dfs(x+1,sum);
		v[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
