#include<bits/stdc++.h>
#define LL long long
#define INF 999999999999
using namespace std;
char ch; 
inline void read(LL &x)
{
	x=0;
	ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-48);
		ch=getchar();
	}
}
LL n,m,k,h[10020],o,mc=INF,f[10020],ds,a[11][10020],p[11],u,v,w,res,cc,sz[10020];
LL mp0[11][10020],mp1[11][10020];
struct ed
{
	LL u,v,w;
}e[2200010];
bool operator < (const ed &x,const ed &y)
{
	return x.w<y.w;
}
inline LL fi(const LL &i)
{
	if(f[i]==i)return i;
	return f[i]=fi(f[i]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	LL i,j;
	for(i=1;i<=m;i++)
	{
		read(u);
		read(v);
		read(w);
		e[++o]={u,v,w};
		e[++o]={v,u,w};
	}
	for(i=1;i<=k;i++)
	{
		read(p[i]);
		for(j=1;j<=n;j++)
		{
			read(a[i][j]);
			e[++o]={n+i,j,a[i][j]};
			e[++o]={j,n+i,a[i][j]};
		}
	}
	sort(e+1,e+o+1);
	for(i=1;i<=o;i++)
	{
		u=e[i].u;
		v=e[i].v;
		if(u<=n&&v<=n)continue;
		e[i].w=-1;
		if(u>n)
		{
			mp0[u-n][v]=i;
		}
		else
		{
			mp1[v-n][u]=i;
		}
	}
	LL S=(1<<k)-1,r;
	for(i=0;i<=S;i++)
	{
		ds=n;
		res=0;
		for(j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				ds++;
				res+=p[j];
				for(r=1;r<=n;r++)
				{
					e[mp0[j][r]].w=a[j][r];
					e[mp1[j][r]].w=a[j][r];
				}
			}
		}
		if(res<mc)
		{
			for(r=1;r<=n+k;r++)
			{
				f[r]=r;
				sz[r]=1;
			}
			cc=0;
			for(r=1;r<=o;r++)
			{
				if(e[r].w==-1)continue;
				u=fi(e[r].u);
				v=fi(e[r].v);
				if(u!=v)
				{
					if(sz[u]>sz[v])
					{
						u^=v^=u^=v;
					}
					f[u]=v;
					sz[v]+=sz[u];
					res+=e[r].w;
					cc++;
					if(cc==ds-1)break; 
					if(res>=mc)
					{
						res=mc+1;
						break;
					}
				}
			}
			mc=min(mc,res);
		}
		for(j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				for(r=1;r<=n;r++)
				{
					e[mp0[j][r]].w=-1;
					e[mp1[j][r]].w=-1;
				}
			}
		}
	}
	cout<<mc;
	return 0;
}
//cheng shi hua de
//freopen you have no egg
//wo yong yuan xi huan mst!
//wo shi chang shu xian ren
