#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int N=1e4+25,M=1e6+5;
int n,m,k;
struct Ed
{
	int u,v,w;
	bool operator <(const Ed &t) const
	{
		return w>t.w;
	}
}e[M],mst[M],nt[M];
int fa[N],sze[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int cty[15][N];
int c[15],id[15][N];
int pos[15];
signed main()
{
#if __MY_TEST__
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=n;i++) fa[i]=i,sze[i]=1;
	int tmst=0;
	sort(e+1,e+m+1,[&](Ed x,Ed y){return x.w<y.w;});
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(sze[fu]>sze[fv]) swap(fu,fv);
		fa[fu]=fv;
		sze[fv]+=sze[fu];
		mst[++tmst]=e[i];
		ans+=e[i].w;
		if(tmst==n-1) break;
	}
	//cerr<<"--------------------------------\n";
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) cty[i][j]=read();
		for(int j=1;j<=n;j++) id[i][j]=j;
		sort(id[i]+1,id[i]+n+1,[&](int x,int y){return cty[i][x]<cty[i][y];});
	}
	//cerr<<tmst<<endl;
	/*
	for(int s=1;s<(1<<k);s++)
	{
		tnt=tmst;
		for(int i=1;i<=tmst;i++) nt[i]=mst[i];
		int tot=n;
		long long sum=0;
		for(int j=1;j<=k;j++)
		{
			if(!((s>>(j-1))&1)) continue;
			tot++;
			sum+=c[j];
			for(int i=1;i<=n;i++) nt[++tnt]=(Ed){tot,i,cty[j][i]};
		}
		if(sum>ans) continue;
		sort(nt+1,nt+tnt+1,[&](Ed x,Ed y){return x.w<y.w;});
		for(int i=1;i<=tot;i++) fa[i]=i,sze[i]=1;
		int cnt=0;
		for(int i=1;i<=tnt;i++)
		{
			int fu=find(nt[i].u),fv=find(nt[i].v);
			if(fu==fv) continue;
			if(sze[fu]>sze[fv]) swap(fu,fv);
			fa[fu]=fv;
			sze[fv]+=sze[fu];
			sum+=nt[i].w;
			cnt++;
			if(cnt==tot-1||sum>ans) break;
		}
		ans=min(ans,sum);
	}*/
	for(int s=1;s<(1<<k);s++)
	{
		int tot=n;
		long long sum=0;
		for(int i=0;i<=k;i++) pos[i]=1;
		priority_queue<Ed>q;
		q.push(mst[1]);
		for(int j=1;j<=k;j++)
		{
			if(!((s>>(j-1))&1)) continue;
			tot++;
			sum+=c[j];
			q.push((Ed){j+n,id[j][1],cty[j][id[j][1]]});
		}
		if(sum>ans) continue;
		for(int i=1;i<=n+k;i++) fa[i]=i,sze[i]=1;
		int cnt=0;
		while(cnt+1<tot)
		{
			auto x=q.top();
			q.pop();
			if(x.u<=n&&pos[0]+1<=tmst) q.push(mst[++pos[0]]);
			else if(pos[x.u-n]+1<=n)
			{
				int np=id[x.u-n][++pos[x.u-n]];
				q.push((Ed){x.u,np,cty[x.u-n][np]});
			}
			int fu=find(x.u),fv=find(x.v);
			if(fu==fv) continue;
			if(sze[fu]>sze[fv]) swap(fu,fv);
			fa[fu]=fv;
			sze[fv]+=sze[fu];
			sum+=x.w;
			cnt++;
			if(cnt==tot-1||sum>ans) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}
