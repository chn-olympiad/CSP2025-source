#include<bits/stdc++.h>
using namespace std;
struct ff
{
	int x,y;
	long long z;
}a[1000005];
bool operator<(ff a,ff b)
{
	return a.z>b.z;
}
bool cmp(ff a,ff b)
{
	return a.z<b.z;
}
long long b[15][10005];
bool cmp2(int x,int y)
{
	return b[x]<b[y];
}
long long c[15];
ff d[100005];
int f[100005];
int find(int x)
{
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
priority_queue<ff> e;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&b[i][j]);
	}
	sort(a+1,a+1+m,cmp);
	int len=0;
	long long ans=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		if(x==y)continue;
		d[++len]=a[i];
		f[x]=y;
		ans+=a[i].z;
		if(len==n-1)break;
	}
	//cout<<ans<<'\n';
	for(int i=0;i<(1<<k);i++)
	{
		long long cnt=0;
		int l=0;
		while(!e.empty())e.pop();
		for(int j=1;j<=len;j++)e.push({d[j].x,d[j].y,d[j].z});
		int tot=n-1;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				cnt+=c[j+1];
				for(int l=1;l<=n;l++)e.push({n+j+1,l,b[j+1][l]});
				tot++;
			}
		}
		for(int j=1;j<=n+10;j++)f[j]=j;
		while(tot&&!e.empty())
		{
			ff g=e.top();
			e.pop();
			int x=find(g.x),y=find(g.y);
			if(x==y)continue;
			cnt+=g.z;
			tot--;
			f[x]=y;
			if(cnt>ans)break;
		}
		//cout<<cnt<<'\n';
		ans=min(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
