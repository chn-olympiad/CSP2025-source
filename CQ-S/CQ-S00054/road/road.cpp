#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct edge
{
	int u,v,w;
}e[M+N*10];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int a[15][N];
int fa[N];
int siz[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void read(int &ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)
	{
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	int tot=m;
	for(int i=1;i<=k;i++)
	{
		read(a[i][0]);
		for(int j=1;j<=n;j++)
		{
			read(a[i][j]);
			e[++tot]={j,n+i,a[i][j]}; 
		 } 
	}
	sort(e+1,e+1+tot,cmp);
	long long ans=1e18;
	for(int s=0;s<(1<<k);s++)
	{
		long long cnt=0;
		int ww=0;
		for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
		for(int i=0;i<k;i++)
		{
			if(s>>i&1) cnt=cnt+1LL*a[i+1][0],ww++;
		}
		int len=0;
		for(int i=1;i<=tot;i++)
		{
			int u=e[i].u,v=e[i].v;
			if(u>n&&(!(s>>u-n-1&1))) continue;
			if(v>n&&(!(s>>v-n-1&1))) continue;
			int x=find(u),y=find(v);
			if(x!=y)
			{
				if(siz[x]>siz[y]) swap(x,y);
				fa[x]=y;
				siz[x]=0;
				siz[y]+=siz[x];
				len++;
				cnt=cnt+1LL*e[i].w;
//				if(i==n-1) break;
				if(len==n+ww-1) break;
			}
		}
//		cout<<s<<" "<<cnt<<"\n";
		if(len==n+ww-1) ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

