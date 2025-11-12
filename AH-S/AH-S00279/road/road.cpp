#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int L=1e5+7;
const int G=5e6+7;
int minw[1005][1005];
int h[L];
struct XB{
	int a,b,val;
}p[G];
int w[15][L];
int c[15]; 
bool cmp(XB x,XB y)
{
	return x.val<y.val;
}
int  find(int x)
{
	if(h[x]==x) return x;
	return h[x]=find(h[x]);
}
void work()
{
	for (int i=1;i<=n;i++)
	{
		h[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	long long ans=0;
	for (int i=1;i<=m;i++)
	{
		int a=p[i].a;int b=p[i].b;
		int ha=find(a);
		int hb=find(b);
		if(ha!=hb)
		{
			ans+=p[i].val;
			h[ha]=hb;
		}
	}
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(minw,0x7f7f7f,sizeof(minw));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].val);
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	if(k==0)
	{work();return 0;}
	if(n<1005&&c[1]==0)
	{
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int d=j+1;d<=n;d++)
				{
					minw[j][d]=min(minw[j][d],w[i][j]+w[i][d]);
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				m++;
				p[m].a=i;
				p[m].b=j;
				p[m].val=minw[i][j];
			}
		}
		work();
		return 0;
	}	
	work();
	return 0;
}
