#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,m,k,h[N],cnt;
int c[15],f[N];
ll ans=1e18;
struct Node
{
	int u,v,w;
}a[N*2],s[N*2];
void ms(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	ms(l,mid),ms(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i].w<a[j].w)
		{
			s[k]=a[i];
			i++;
		}
		else
		{
			s[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		s[k]=a[i];
		i++,k++;
	}
	while(j<=r)
	{
		s[k]=a[j];
		j++,k++;
	}
	for(int o=l;o<=r;o++)
		a[o]=s[o];
	return ;
}
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int fnd(int x)
{
	if(f[x]!=x) return f[x]=fnd(f[x]);
	return x;
}
void wk(int num)
{
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	ll res=0;
	for(int i=1;i<=m;i++)
	{
		if( a[i].u>n && ((num>>(a[i].u-n-1))&1)==0) continue;
		if( a[i].v>n && ((num>>(a[i].v-n-1))&1)==0) continue;
		int tx=fnd(a[i].u),ty=fnd(a[i].v);
		if(tx!=ty)
		{
			f[tx]=ty;
			res=(ll)res+a[i].w;
			if(res>ans) return;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(((num>>(i-1))&1) ==1)
			res+=c[i];
	}
	ans=min(ans,res);
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
			int p;
			scanf("%d",&p);
			m++;
			a[m].u=n+i,a[m].v=j,a[m].w=p;
		}
	}
//	sort(a+1,a+1+m,cmp);
	ms(1,m);
	bool bz=0;
	for(int i=1;i<=k;i++)
	{
		if(c[i])
		{
			bz=1;
			break;
		}
	}
	if(!bz)
	{
		wk((1<<k)-1);
		printf("%lld",ans);
		return 0;
	}
//	printf("%d\n",m);
	for(int i=0;i<(1<<k);i++)
	{
		wk(i);
	}
	printf("%lld",ans);
//	for(int i=1;i<=m;i++)
//	{
//		if(a[i].u>0||)
//	}
	return 0;
}
