#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[1000],b[1000],c[1000],ans,d[1000],n,m;
void dfs(int x)
{
	if(x>n)
	{
		int rs=0,trs=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1&&trs<a[d[i]]) rs++;
			else if(b[i]==0||trs>=a[d[i]]) trs++;
		}
		if(rs>=m) ans++;
		ans%=mod;
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				c[i]=1;
				d[i]=x;
				dfs(x+1);
				c[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<int(s.size());i++)
	{
		b[i+1]=s[i]-'0';
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
