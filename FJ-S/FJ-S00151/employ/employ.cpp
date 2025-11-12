#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505],p[505];
string s;
bool vis[505];
int ans;
void dfs(int d,int num)
{
	if(num>n-m) return;
	if(d>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(num>=c[i]||s[d-1]=='0') dfs(d+1,num+1);
		else dfs(d+1,num);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<"\n";
}