#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[101010],vis[101010];
int ans,sum,n;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int ch,int id,int flag,int las)
{
	if(id==flag+1)
	{
		if(sum>a[ch]*2)
		ans++,ans%=998244353;
		return ;
	}
	for(int i=las+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(id!=1)
			{
				sum+=a[i];
				dfs(ch,id+1,flag,i);
				sum-=a[i]; 
			}
			else
			{
				sum+=a[i];
				dfs(i,id+1,flag,i);
				sum-=a[i]; 
			}
			vis[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++)
	{
		dfs(0,1,i,0);
	}
	cout<<ans;
	return 0;
 }
