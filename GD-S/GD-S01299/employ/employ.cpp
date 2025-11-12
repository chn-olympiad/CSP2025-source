#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],mod=998244353,js=0,tg=0,t[505],ans;
string s;
void dfs(long long i,long long syg)
{
	if(i==tg)
	{
		ans+=t[i]-syg;
		return ;
	}
	for(int j=t[i];j>syg;j--)
	{
		dfs(i+1,t[i]);
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
		if(a[i]<js)
			js++;
		if(s[i-1]==0)
			js++;
		else
		{
			tg++;
			t[tg]=i;
		}
	}
	if(tg==0)
	{
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
