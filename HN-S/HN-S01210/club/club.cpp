#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
long long t,n,a[N][4],h[4],s;
bool f[N];
struct stu
{
	long long d,p,f,e;
}b[N],c[N],d[N]; 
long long read()
{
	register long long x=0,k=1;
	register char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
bool comp(stu x,stu y)
{
	return x.e>y.e;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while (t--)
	{
		s=0;
		memset(h,0,sizeof(h));
		memset(f,0,sizeof(f));
		memset(b,-1,sizeof(b));
		memset(d,0x3f,sizeof(d));
		n=read();
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=3;++j)
			{
				a[i][j]=read();
				if (b[i].d<a[i][j])
				{
					b[i].d=a[i][j];
					b[i].p=j;
					b[i].f=i;
				}
				if (d[i].d>a[i][j])
				{
					d[i].d=a[i][j];
					d[i].p=j;
					d[i].f=i;
				}
			}
			for (int j=1;j<=3;++j)
				if (b[i].p!=j&&d[i].p!=j)
				{
					c[i].d=a[i][j];
					c[i].p=j;
					c[i].f=i;
					break;
				}
			b[i].e=b[i].d-c[i].d;
			c[i].e=c[i].d-d[i].d;
		}
		sort(b+1,b+n+1,comp);
		sort(c+1,c+n+1,comp);
		sort(d+1,d+n+1,comp);
		for (int i=1;i<=n;++i)
			if (h[b[i].p]<(n>>1))
			{
				s+=b[i].d;
				++h[b[i].p];
				f[b[i].f]=1;
			}
		for (int i=1;i<=n;++i)
			if (!f[c[i].f]&&h[c[i].p]<(n>>1))
			{
				s+=c[i].d;
				++h[c[i].p];
				f[c[i].f]=1;
			}
		for (int i=1;i<=n;++i)
			if (!f[d[i].f])
				s+=d[i].d;
		printf("%lld\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

