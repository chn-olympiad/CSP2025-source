#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[15][100005],f[100005],c[11],ans=100000000;
struct node{
	int u,v,w;
}a[1000005];
node hwz[10000005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int h)
{
	if(h==f[h]) return h;
	else return f[h]=find(f[h]);
}
void u(int h,int w)
{
	int hh=find(h),ww=find(w);
	f[hh]=ww;
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		int i=0,num=0;
		for(int j=1;j<=n;j++)
		{
			f[j]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(i==n-1) break;
			int h=a[j].u,w=a[j].v;
			if(find(h)!=find(w))
			{
				i++;
				u(h,w);
				num+=a[j].w;
			}
		}
		printf("%d",num);
		return 0;
	}
} 
