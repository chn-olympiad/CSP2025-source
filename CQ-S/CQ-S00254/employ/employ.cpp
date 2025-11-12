#include<bits/stdc++.h>
using namespace std;
int a[505],b[505];
bool v[505];
int n,m;
string s;
int ans=0;
void dfs(int id,int cnt)
{
	if(id>n)
	{
		if(n-cnt>=m)
		{
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			if(cnt>=a[i])
			{
				dfs(id+1,cnt+1);
			}
			else if(s[id-1]=='0')
			{
				dfs(id+1,cnt+1);
			}
			else
			{
				dfs(id+1,cnt);
			}
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
//rp+=998244353 QWQ
