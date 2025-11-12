#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10015,M=1e6+5;
int n,m,k,fa[N],ans,dis[15][N],cost[15];
struct node
{
	int val,u,v;
}a[M],b[N],c[N*11];
bool cmp(node ai,node bi){return ai.val<bi.val;}
int find(int s){return fa[s]==s?s:fa[s]=find(fa[s]);}
inline int read()
{
	int s=0;
	char ai=getchar();
	while(ai<'0'||ai>'9') ai=getchar();
	while(ai>='0'&&ai<='9') s=s*10+ai-'0',ai=getchar();
	return s;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].val=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1,cnt=0;i<=m&&cnt<n-1;i++)
	{
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v) b[++cnt]=a[i],fa[u]=v,ans+=a[i].val;
	}
	for(int i=1;i<=k;i++) 
	{
		cost[i]=read();
		for(int j=1;j<=n;j++) dis[i][j]=read();
	}
	int bs=n-1;
	for(int i=1;i<(1<<k);i++)
	{
		int dq=n-1,maxn=0,num=0,sl=0;
		for(int j=1;j<=n-1;j++) c[j]=b[j];
		for(int j=1;j<=k;j++) if((i>>(j-1))&1){maxn=j,sl++,num+=cost[j];for(int z=1;z<=n;z++) c[++dq]={dis[j][z],n+j,z};}
		for(int j=1;j<=n+maxn;j++) fa[j]=j;
		sort(c+1,c+dq+1,cmp);
		bs+=dq;
//		cout<<num<<' '<<sl<<endl;
//		for(int j=1;j<=dq;j++) cout<<c[j].u<<' '<<c[j].v<<' '<<c[j].val<<endl;
		for(int j=1,cnt=0;j<=dq&&cnt<n+sl-1;j++)
		{
			int u=find(c[j].u),v=find(c[j].v);
			if(u!=v) fa[u]=v,num+=c[j].val;
		}
//		cout<<num<<endl;cout<<endl;
		ans=min(ans,num);
	}
	printf("%lld",ans);
	return 0;
}

