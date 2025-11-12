#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define ll unsigned long long
const int N=1e4+15,M=2e6+10;
int n,m,k,totv,c[11],tote,prt[N],flag=1,ind[N],tos[N];
ll ans=0x3f3f3f3f3f3f3f3fll;
struct edge
{
	int u,v,p;ll w;
	bool pd;
	bool operator<(const edge &x)
	{
		if(pd^x.pd) return pd;
		return w<x.w;
	}
	edge(){pd=0;}
 }e[M];
inline bool cmp(const edge &a,const edge &b){return a.p<b.p;}
int find(int p){return p==prt[p]?p:prt[p]=find(prt[p]);}
inline ll kruskl()
{
	for(int i=1;i<=n;i++) prt[i]=i;
	ll sum=0;int cnte=0;
	for(int i=1;i<=m+n*k;i++)
	{
		if(!e[i].pd) break;
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		prt[x]=y;sum+=e[i].w;cnte++;
		ind[e[i].u]++;ind[e[i].v]++;
		tos[e[i].u]=tos[e[i].v]=e[i].w;
		//cout<<e[i].u<<' '<<e[i].v<<ind[e[i].u]<<' '<<endl;
		if(cnte==n-1) break;
	}
	return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) tote++,cin>>e[tote].u>>e[tote].v>>e[tote].w,e[tote].pd=1,e[tote].p=tote;
	for(int i=1;i<=k;i++) 
	{
		cin>>c[++totv];
		if(c[totv]) flag=0;
		for(int j=1;j<=n;j++)
		{
			int t;cin>>t;
			e[++tote].u=i+n;e[tote].v=j;e[tote].w=t;e[tote].p=tote;
		}
	}
	if(flag)
	{
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) e[m+(i-1)*n+j].pd=1;
		sort(e+1,e+m+n*k+1);
		n+=k;
		ll sum=kruskl();
		n-=k;
		for(int i=1;i<=k;i++) if(ind[i+n]==1) sum-=tos[i+n];
		cout<<sum;
		return 0;
	}
	for(int t=0;t<(1<<k);t++)
	{
		ll sum=0;int popc=0;
		for(int i=1;i<=k;i++)
		{
			if((t>>(i-1)&1)==0) continue;
			for(int j=1;j<=n;j++) e[m+(i-1)*n+j].pd=1;
			sum+=c[i];popc++;
		}
		n+=popc;
		sort(e+1,e+m+n*k+1);
		sum+=kruskl();
		//cout<<kruskl()<<endl;
		ans=min(ans,sum);
		sort(e+1,e+m+n*k+1,cmp);
		n-=popc;
	}
	cout<<ans;
}



/*
我常常追忆过去。

生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲、揉捻成天上朵朵白云。  

云朵之间亦有分别：积云厚重，而卷云缥缈。生命中震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只剩下些许残骸。
追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过于模糊却又堕入虚无。
只有薄雾间的山水、面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。

回忆总在不经意间将我裹进泛黄的纸页中。分别又重聚的朋友，推倒又重建的街道，种种线索帮助我从某个具体时间点沿时间的河逆流而上。
曾经的日子无法重来，我也不过是一个过客，但我仍然渴望在每一次追忆之旅中留下闲暇时间，在特定的场景，在岁月的朦胧中瞭望过去的自己，获取尽可能多的甜蜜。
欢乐的时光流过我的身体，我便心满意足。

过去已经凝结。我带着回忆向前，只是时常疏于保管，回忆也改变着各自的形态，这为我的追忆之旅带来些许挑战。

我该在哪里停留？我问我自己。

（必备课文没背清楚/kk）
Luogu uid=1524111
*/
