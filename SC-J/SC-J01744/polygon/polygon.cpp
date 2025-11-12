#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
bool vis[5010];
int jc(int d)
{
	if(d==1) return 1;
	return jc(d-1)*d;
}
void dfs(int d,int maxn,int sum)
{
	if(d==0)
	{
		if(maxn*2<sum) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			//cout<<d-1<<' '<<max(a[i],maxn)<<' '<<sum+a[i]<<endl;
			dfs(d-1,max(a[i],maxn),sum+a[i]);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(vis,0,sizeof(vis));
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(n,0,0);
		ans/=jc(n);
		t+=ans;
		ans=0;
	}
	cout<<t;
	return 0;	
} 