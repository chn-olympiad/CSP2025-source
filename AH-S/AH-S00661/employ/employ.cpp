#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,a[maxn],t[maxn],ans;
bool vis[maxn];
void dfs(int x,int num)
{
	if(x>=n+1&&num>=m)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			if(a[i]==1&&t[i]>x-num-1)dfs(x+1,num+1);
			else dfs(x+1,num);
			vis[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
