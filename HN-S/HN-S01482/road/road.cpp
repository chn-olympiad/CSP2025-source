#include<bits/stdc++.h>
#define ll long long
#define N 0
using namespace std;
inline int in()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}return s*w;
}

struct node
{
	int u,v,w;
}dl[1000002];
int n,m,k,c[12],a[12][10002],ans;

bool sort1(node xx,node yy)
{
	return xx.w<yy.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in();m=in();k=in();
	for(int i=1;i<=m;i++)
	{
		dl[i].u=in();dl[i].v=in();dl[i].w=in();
		ans+=dl[i].w;
	}
	sort(dl+1,dl+1+m,sort1);
	for(int i=1;i<=k;i++)
	{
		c[i]=in();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=in();
		}
	}
	printf("%lld\n",ans);
	return 0;
}

