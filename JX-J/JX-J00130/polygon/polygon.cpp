#include<bits/stdc++.h>
using namespace std;
int l[510];
int n,sum,ans;
void dfs(int x,int xget,int lmax,int lsum,int now)
{
	if(xget>=x)
	{
		if(lsum>2*lmax)
		{
			ans++;
		}
		return ;
	}
	if(now>n) return ;
	dfs(x,xget+1,max(lmax,l[now]),lsum+l[now],now+1);
	dfs(x,xget,lmax,lsum,now+1);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
		dfs(i,0,0,0,1);
	cout<<ans;
	return 0;
}
