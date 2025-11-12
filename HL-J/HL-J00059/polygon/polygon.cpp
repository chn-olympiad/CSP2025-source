#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int maxst1=0;
int sumst1=0;
int ans=0;
long long ans2=0;
bool vis[100000];
bool vis2[1000][1000];
void dfs(int sum,int maxn,int st)
{
	if(st>=3)
	{
		if(sum>maxn*2)
		{
			bool b=false;
			for(int i=0;i<=ans2;i++)
			{
				bool c=true;
				for(int j=1;j<=n;j++)
					if(vis[j]!=vis2[i][j])
					{
						c=false;
						break;
					}
				if(c)
				{
					
					b=true;
					break;
				}				
			}
			
			if(!b)
			{
				ans=(ans+1)%998244353;
				ans2++;
				for(int i=1;i<=n;i++)
					vis2[ans2-1][i]=vis[i];
				
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(sum+a[i],max(maxn,a[i]),st+1);
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxst1=max(maxst1,a[i]);
		sumst1+=a[i];
	}
	if(n==3)
	{
		if(maxst1*2<sumst1)
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
	
	
	
}
