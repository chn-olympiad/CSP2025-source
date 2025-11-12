#include<bits/stdc++.h>
using namespace std;

int fa[20010],c[20010],in[20010];

struct node
{
	int x,y,z,id;
}a[2000010];

bool cmp(node a,node b)
{
	return a.z<b.z;
}

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=0;
	for(int i=1;i<=k;i++) 
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) 
		{
			a[++m].x=n+i,a[m].y=j,a[m].id=i;
			scanf("%d",&a[m].z);
		}
	}
	long long ans=1e18;
	sort(a+1,a+m+1,cmp);
	in[0]=1;
	for(int S=0;S<(1<<k);S++)
	{
		long long res=0;
		int tot=n,now=0,flag=0;
		for(int i=1;i<=k;i++) 
		{
			in[i]=(S>>(i-1))&1;
			if(in[i]) res+=c[i],tot++;
			if(c[i]==0&&!in[i]) flag=1;
		}
		if(flag) continue;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x=a[i].x,y=a[i].y,z=a[i].z,id=a[i].id;
			if(!in[a[i].id]) continue;
			x=find(x),y=find(y);
			if(x==y) continue;
			fa[x]=y,res+=z,now++;
			if(now==tot-1) break;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
}
