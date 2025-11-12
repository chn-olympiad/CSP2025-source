#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();
	while(1)
	{
		if(ch=='-'||ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	int fl=1,s=0;
	if(ch=='-')fl=-1,ch=getchar();
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*fl;
}
int n,m,k,e[11000],f[11000],q,d[20];
long long b[20],c[20][11000],ma;
struct ll
{
	int x,y;
	long long w;
}a[1100000],g[4100000];
bool cmp(ll a,ll b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
long long ksc(int q,int nn)
{
	sort(g+1,g+1+q,cmp);
	for(int i=1;i<=nn;i++)f[i]=i;
	long long ans=0;
	for(int i=1;i<=q;i++)
	{
//		cout<<g[i].x<<" "<<g[i].y<<endl;
		int xx=find(g[i].x);
		int yy=find(g[i].y);
		if(xx!=yy)
		{
			f[xx]=yy;
			ans+=g[i].w;
		}
	}
	int x=find(f[1]);
	for(int i=2;i<=n;i++)if(find(f[i])!=x)return 1e18;
//	cout<<ans<<endl;
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read(),a[i].w=read();
	for(int i=1;i<=k;i++)
	{
		b[i]=read();
		for(int j=1;j<=n;j++)c[i][j]=read();
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int xx=find(a[i].x);
		int yy=find(a[i].y);
		if(xx!=yy)
		{
			e[++q]=i;
			f[xx]=yy;
			ans+=a[i].w;
			ma=a[i].w;
		}
	}
	long long minn=ans;
	for(int i=1;i<(1<<k);i++)
	{
		int p=0;
		long long s=0;
		for(int j=1;j<=q;j++)g[j]=a[e[j]];
		int qq=q,gs=0;
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				s+=b[j];
				gs++;
				for(int kk=1;kk<=n;kk++)
				{
					if(c[j][kk]>ma)continue;
					g[++qq].x=n+gs;
					g[qq].y=kk;
					g[qq].w=c[j][kk];
				}
			}
		}
//		cout<<qq<<" "<<n+p<<endl;
		minn=min(minn,s+ksc(qq,n+gs));
	}
	cout<<minn;
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
