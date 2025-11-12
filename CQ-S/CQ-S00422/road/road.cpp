//李老师保佑我AC
#include<bits/stdc++.h>
#define in long long
using namespace std;
in n,m,k;
in fa[10005];
in c[15];
in t[2005][2005];
in mu[10005];
in las[2005][2005];
in vis[15];
struct yyc
{
	in x,y,z;
	in id;
}a[1000005];
bool cmp(yyc x,yyc y)
{
	return x.z<y.z;
}
in getfather(in v)
{
	if(fa[v]==v)
	{
		return v;
	}
	else
	{
		fa[v]=getfather(fa[v]);
		return fa[v];
	}
}
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(in i=1;i<=n;i++)
	{
		fa[i]=i;
		if(n<=1e3)
		{
			for(int j=1;j<=n;j++)
			{
				t[i][j]=1e18;
			}
			t[i][i]=0;
		}
	}
	in cnt=0;
	for(in i=1;i<=m;i++)
	{
		in x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		cnt++;
		a[cnt].x=x,a[cnt].y=y,a[cnt].z=z,a[cnt].id=cnt;
		if(k==0)
		{
			continue;
		}
		t[x][y]=min(t[x][y],z);
		t[y][x]=t[x][y];
	}
	if(n<=1000)
	{
		floyd();
	}
	in ans=0;
	for(in i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(in j=1;j<=n;j++)
		{
			scanf("%lld",&mu[j]);
		}
		for(in j=1;j<=n;j++)
		{
			for(in o=j+1;o<=n;o++)
			{
				if(t[j][o]+c[las[j][o]]>mu[j]+mu[o]+c[i])
				{
					cnt++;
					a[cnt].x=j;
					a[cnt].y=o;
					a[cnt].z=mu[j]+mu[o];
					a[cnt].id=cnt;
					t[j][o]=mu[j]+mu[o];
					las[j][o]=i;
				}
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(in i=1;i<=cnt;i++)
	{
		in fx=getfather(a[i].x);
		in fy=getfather(a[i].y);
		if(fx!=fy)
		{
			fa[fy]=fx;
			ans+=a[i].z;
			if(a[i].id>m)
			{
				in p=las[a[i].x][a[i].y];
				if(!vis[p])
				{
					ans+=c[p];
					vis[p]=1;
				}
			}
		}
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
