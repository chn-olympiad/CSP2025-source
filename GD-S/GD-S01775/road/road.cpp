#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct node
{
	int fi,se,th;
};
int n,m,k,c[15],a[15][10005],pre[10005];
vector<node>E;
int find(int x)
{
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
void join(int x,int y)
{
	pre[find(x)]=find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++)
		pre[i]=i;
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=read();
		v=read();
		w=read();
		sum+=w;
		E.push_back({u,v,w});
	}
	if(k==0)
	{
		printf("%lld",sum);
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int t=1;t<=n;t++)
			a[i][t]=read();
		for(int t=1;t<n;t++)
			for(int j=t+1;j<=n;j++)
				E.push_back({t,j,a[i][t]+a[i][j]});
	}
	sort(E.begin(),E.end(),[](node x,node y)
	{
		return x.th<y.th;
	});
	int s=0;
	for(auto i:E)
	{
		if(find(i.fi)!=find(i.se))
		{
			join(i.fi,i.se);
			ans+=i.th;
		}
		if(s==n-1)
			break;
	}
	printf("%lld",ans);
	return 0;
}
