#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=0;
int n;
bool vis[5005];
map<string,bool>mp;
void dfs(int step,int l,int sum,int maxn,int last)
{
	if(step==l)
	{
		if(sum>2*maxn) 
		{
			ans++;
		}
		ans%=998244353;
		return;
	}		
	for(int i=last+1;i<=n;i++)
	{

		if(!vis[i])
		{
			vis[i]=1;
			dfs(step+1,l,sum+a[i],max(maxn,a[i]),i);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-0x3f3f3f3f,sum=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==3)
	{
		if(sum>2*maxn) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		dfs(0,i,0,-0x3f3f3f3f,0);
		memset(vis,0,sizeof(vis));
	}
	cout<<ans<<endl;
	return 0;
}
