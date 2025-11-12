#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2000002+5;
LL n,m,tot,k,a[11][N],c[N],us[N],mi[N][11];
struct E{
	LL u,v,w;
}e[N];
vector<LL>G[N];
LL lmin(LL x,LL y)
{
	if(x<y)return x;
	return y;
}
LL find(LL x)
{
	if(us[x]!=x)us[x]=find(us[x]);
	return us[x];
}
bool cable(LL x,LL y)
{
	x=find(x);y=find(y);
	if(x==y)return false;
	else return true;
}
bool combine(LL x,LL y)
{
	x=find(x);y=find(y);
	if(x==y)return false;
	for(int i=1;i<=k;i++)
	{mi[y][i]=lmin(mi[y][i],mi[x][i]);}
	us[x]=y;
	return true;
}
LL Kruskal(){
	LL ans=0;
	for(int tot=1,i=1;tot<n;i++)
	{
		if(cable(e[i].u,e[i].v))
		{
			LL x=find(e[i].u),y=find(e[i].v),mii=e[i].w;
			for(int j=1;j<=k;j++)
			{
				mii=lmin(mii,c[j]+mi[x][j]+mi[y][j]);
			}
			ans+=mii;
			tot++;
			combine(x,y);
			
			//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
		}
	}
	return ans;
}
bool cmp(E x,E y)
{
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)us[i]=i;
	for(int i=1;i<=m;i++)
	{
		LL u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		//G[u].push_back(v);
		//G[v].push_back(u);
		e[++tot]={u,v,w};
		e[++tot]={v,u,w};
	}
	sort(e+1,e+tot+1,cmp);
	//memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&mi[j][i]);			
		}
	}
	LL ans=Kruskal();
	printf("%lld",ans);
/*	if(k==0)
	{
		
		return 0;
	}*/
		
	return 0;
}
