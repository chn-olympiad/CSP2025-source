#include<bits/stdc++.h>
using namespace std;
struct ss{
	int x,y,z;
}a[2000010],b[1000010];
int l,m,n,k,nn,len,maxx;
int c[11],w[11][10100],vc[11],f[10100];
long long ans=9999999999999;
bool cmp(ss x,ss y)
{
	return x.z<y.z;
}
void add(int x,int y,int z)
{
	a[++l].y=y;a[l].x=x;a[l].z=z;
}
void add1(int x,int y,int z)
{
	b[++len].y=y;b[len].x=x;b[len].z=z;
}
int find(int x)
{
	if(x!=f[x])
		return f[x]=find(f[x]);
	return x;
}
void xx()
{
	for(int i=1;i<=k;i++)
		if(vc[i]==1)
		{
			nn++;
			f[n+i]=n+i;
			for(int j=1;j<=n;j++)
				add1(j,n+i,w[i][j]);
		}
	sort(b+1,b+1+len,cmp);
}
void f1(long long tot)
{
	len=0;nn=n;
	xx();
	int t1=1,t2=1,tt=1,fx,fy,fi=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(t1<=m)
	{
		if(tt==nn)
		{
			fi=1;
			break;
		}
		if(t2<=len&&b[t2].z<a[t1].z)
		{
			fx=find(b[t2].x);fy=find(b[t2].y);
			if(fx!=fy)
			{
				f[fx]=fy;
				tt++;
				tot+=b[t2].z;
			}
			t2++;
		}
		else
		{
			fx=find(a[t1].x);fy=find(a[t1].y);
			if(fx!=fy)
			{
				f[fx]=fy;
				tt++;
				tot+=a[t1].z;
			}
			t1++;
		}
	}
	if(fi)
		ans=min(ans,tot);
}
void gj(int x,long long tot)
{
	if(x>k)
		f1(tot);
	else
	{
		gj(x+1,tot);
		if(c[x]<maxx)
		{
			vc[x]=1;
			gj(x+1,tot+c[x]);
			vc[x]=0;
		}
	}
}
void ff1()
{
	int tt=1,fx,fy;
	long long tot=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(tt==n)
			break;
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			tt++;
			tot+=a[i].z;
		}
	}
	ans=min(ans,tot);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)
			swap(x,y);
		add(x,y,z);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	}
	sort(a+1,a+1+m,cmp);
	maxx=a[m].z;
	if(k==0)
		ff1();
	else
		gj(1,0);
	cout<<ans<<endl;
	return 0;
}