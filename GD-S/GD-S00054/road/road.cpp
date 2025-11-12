#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,b[15],c[10005];
bool vis[100000],fg[15];
struct R
{
	int x,y,v,f;
}a[10005];
bool cmp(R d,R e)
{
	return d.v<e.v;
}
void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].v;
		a[i].f=0;
	}
	int sum=m+1;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int z=j+1;z<=n;z++)
			{
				a[sum].x=j;
				a[sum].y=z;
				a[sum].v=c[j]+c[z]+b[i];
				a[sum].f=i;
				sum++;
			}
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(vis[a[i].x]==0||vis[a[i].y]==0)
		{
			if(a[i].f>0)
			{
				if(fg[a[i].f]==1)
				{
					ans-=b[a[i].f];
				}
				else
				{
					fg[a[i].f]=1;
				}
			}
			vis[a[i].x]=1;
			vis[a[i].y]=1;
			ans+=a[i].v;
		}
	}
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	return 0;
 } 
