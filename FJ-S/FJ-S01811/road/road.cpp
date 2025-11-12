#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+21,M=1e6+1e5+5;
struct edge
{
	int u,v;
	ll w;
}e[M];
int u,v,n,m,k,t,fa[N];
ll c[11],mn[11],w,id1[11],id2[11],a[11][N],ans,cnt;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
} 
void pre()
{
	for(int i=1;i<=k;++i)
	{
		if(!id1[i])
			continue;
		ll wei=mn[i];
		ll kin=id2[i];
		for(int j=1;j<=n;++j)
		{
			if(j==kin)
				continue;
			e[++t].u=kin,
			e[t].v=j,
			e[t].w=wei+a[i][j];
		//	cout<<"kin="<<kin<<" v="<<j<<" w="<<wei+a[i][j]<<endl;	
		}
		//cout<<"one passed\n";
	}
	return;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
		mn[i]=1e15;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%lld",&u,&v,&w);
		e[++t].u=u;e[t].v=v;e[t].w=w;
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",&c[i]);
		if(c[i]==0)
			id1[i]=1;
		for(int j=1;j<=n;++j)
		{
			scanf("%lld",&a[i][j]);
			if(id1[i])
			{
				//cout<<mn[i]<<endl; 
				if(a[i][j]<mn[i])
				{
					mn[i]=a[i][j];
					id2[i]=j;
					//cout<<"id2="<<j<<endl;
				}
			}
		}	
	}
	if(k>0)
		pre();
	sort(e+1,e+t+1,cmp);
	//cout<<t<<endl;
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=t;++i)
	{
		//cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
		int fx=find(e[i].u),fy=find(e[i].v);
		//cout<<fx<<' '<<fy<<endl; 
		if(fx==fy)
			continue;
		++cnt;
		fa[fx]=fy;
		ans+=e[i].w;
		if(cnt>=n-1)
			break;
		//cout<<cnt<<' '<<ans<<endl;
	}
	printf("%lld",ans); 
	return 0;
}/*
3
3
1
1 2
99
1 3 2
2 3 3
0 0 99 99
exp:25+48
*/
