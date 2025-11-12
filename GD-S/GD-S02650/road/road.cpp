#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long int ans;
long long int f[20021];
long long int find(long long int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return find(f[x]);
}
struct node
{
	long long int v;
	int x;
	int y;
}t[4000001];
node pc[4000010];
bool cmp(const node & a,const node & b)
{
	return a.v<b.v;
}
void msort(int l,int r)
{
	if(l==r)
	{
		return;
	}
	int mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	int x=l;
	int y=mid+1;
	int w=0;
	while(x<=mid&&y<=r)
	{
		if(cmp(t[x],t[y]))
		{
			w++;
			pc[w]=t[x];
			x++;
		}
		else
		{
			w++;
			pc[w]=t[y];
			y++;
		}
	}
	while(x<=mid)
	{
		w++;
		pc[w]=t[x];
		x++;
	}
	while(y<=r)
	{
		w++;
		pc[w]=t[y];
		y++;
	}
	for(int i=l,j=1;i<=r;i++,j++)
	{
		t[i]=pc[j];
	}
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int x,y,v,cnt;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)f[i]=i; 
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&v);
		if(x>=y)swap(x,y);
		cnt++;
		t[cnt].v=v;
		t[cnt].x=int(x);
		t[cnt].y=int(y);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&v);
		for(int j=1;j<=n;j++)
		{
			cnt++;
			t[cnt].x=j;
			t[cnt].y=n+i;
			scanf("%lld",&t[cnt].v);
		}
	}
//	sort(t+1,t+cnt+1,cmp);
	msort(1,cnt);
	int p=0;
	for(int i=1;i<=cnt;i++)
	{
		x=find(t[i].x);
		y=find(t[i].y);
		if(x!=y)
		{
			p++;
			f[x]=y;
			ans+=t[i].v;
			if(p==n+k-1)break;
		}
	}
	printf("%lld",ans);
	return 0;
}
