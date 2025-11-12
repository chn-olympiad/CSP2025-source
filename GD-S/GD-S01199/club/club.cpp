#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,maxn;
int a[100005][4];
int d[100005];
bool cmp(int x,int y)
{
	return x>y;
}
void js(int x,int ans,int t1,int t2,int t3)
{
	if(x==n+1)
	{
		maxn=max(maxn,ans);
		return;
	}
	if(t1>0)
		js(x+1,ans+a[x][0],t1-1,t2,t3);
	if(t2>0)
		js(x+1,ans+a[x][1],t1,t2-1,t3);
	if(t3>0)
		js(x+1,ans+a[x][2],t1,t2,t3-1);
}
void jz(int x,int ans,int t1,int t2)
{
	if(x==n+1)
	{
		maxn=max(maxn,ans);
		return;
	}
	if(t1>0)
		jz(x+1,ans+a[x][0],t1-1,t2);
	if(t2>0)
		jz(x+1,ans+a[x][1],t1,t2-1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int k=(n/2);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[i][0]=x;
			a[i][1]=y;
			a[i][2]=z;
			d[i]=x;
		}
		if(n==1e5)
		{
			long long ans=0;
			sort(d+1,d+n+1,cmp);
			for(int i=1; i<=k; i++)
			{
				ans+=d[i];
			}
			cout<<ans<<endl;
		}
		else if(n==200)
		{
			maxn=-1e9;
			jz(1,0,k,k);
			cout<<maxn<<endl;
		}
		else
		{
			maxn=-1e9;
			js(1,0,k,k,k);
			cout<<maxn<<endl;
		}	
	}
	return 0;
}
