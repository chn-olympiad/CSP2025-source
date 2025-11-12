#include<bits/stdc++.h>
using namespace std;
int T,n,vis[100005],sumx,sumy,sumz,ans=0;
struct xx
{
	int x,id;
}vx[100005];
struct yy
{
	int y,id;
}vy[100005];
struct zz
{
	int z,id;
}vz[100005];
struct node
{
	int x,y,z;
}a[100005];
bool cmp1(xx a,xx b)
{
	return a.x>b.x;
}
bool cmp2(yy a,yy b)
{
	return a.y>b.y;
}
bool cmp3(zz a,zz b)
{
	return a.z>b.z;
}
void sol()
{
	ans=0;
	sumx=0;
	sumy=0;
	sumz=0;
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&vx[i].x,&vy[i].y,&vz[i].z);
		vx[i].id=i;
		vy[i].id=i;
		vz[i].id=i;
		a[i].x=vx[i].x;
		a[i].y=vy[i].y;
		a[i].z=vz[i].z;
	}
	sort(vx+1,vx+n+1,cmp1);
	sort(vy+1,vy+n+1,cmp2);
	sort(vz+1,vz+n+1,cmp3);
	for(int i=1;i<=n;i++)
	{
		if(vis[vx[i].id]==0&&a[vx[i].id].x>a[vx[i].id].y&&a[vx[i].id].x>a[vx[i].id].z&&sumx+1<=n/2)
		{
			vis[vx[i].id]=1;
			sumx++;
			ans+=vx[i].x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[vy[i].id]==0&&a[vy[i].id].y>a[vy[i].id].x&&a[vy[i].id].y>a[vy[i].id].z&&sumy+1<=n/2)
		{
			vis[vy[i].id]=1;
			sumy++;
			ans+=vy[i].y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[vz[i].id]==0&&a[vz[i].id].z>a[vz[i].id].x&&a[vz[i].id].z>a[vz[i].id].y&&sumz+1<=n/2)
		{
			vis[vz[i].id]=1;
			sumz++;
			ans+=vz[i].z;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		sol();
	}
	return 0;
}
