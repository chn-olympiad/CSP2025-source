#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int u,v,w;
}qz[1010005];
int n,m,k,s,x,u,v,w,tot,ans,fa[11005],tot1,cnt;
int find(int x)
{
	return fa[x]==x?x:find(fa[x]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	tot1=n;
	for(int i=1;i<=11000;i++)
		fa[i]=i;
	while(m--)
	{
		u=read(),v=read(),w=read();
		qz[++tot]=(node){u,v,w};
	}
	while(k--)
	{
		s=read();
		++tot1;
		for(int i=1;i<=n;i++)
			x=read(),qz[++tot]=(node){tot1,i,x};
	}
	sort(qz+1,qz+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		if(find(qz[i].u)!=find(qz[i].v))
		{
			fa[find(qz[i].u)]=find(qz[i].v);
			ans+=qz[i].w;
			++cnt;
			if(cnt==n+tot1)
				break;
		}
	cout<<ans;
	return 0;
}
