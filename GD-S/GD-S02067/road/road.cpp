#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
char st;
int n,m,k,u,v,w,tx,id,cnt,tot2,c[15],wx[15][10005],fa[20005],bx[2000005],rk[2000005];
pair<ll,int>pre[200005];
vector<int>vx;
ll ans;
char en;
struct node{
	int u,v;ll w;int id,rk;
}a[1000005],gx[200005],gx2[200005],gx3[200005];
int find(int x)
{
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node x,node y){return x.w<y.w;}
bool cmp2(node x,node y){return x.id<y.id;}
void init()
{
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			pre[++tot2]={wx[i][j],i*n+j};
	sort(pre+1,pre+tot2+1);
	for(int i=1;i<=tot2;i++)
		rk[pre[i].second]=i;
}
void mk(int tot)
{
//	for(int i=1;i<=tot;i++)
//		cout<<gx[i].u<<" "<<gx[i].v<<" "<<gx[i].w<<" "<<gx[i].id<<" "<<gx[i].rk<<" "<<rk[gx[i].rk]<<" PreSort\n";
	for(int i=1;i<=(k+1)*n;i++)
		bx[i]=0;
	for(int i=1;i<=tot;i++)
		bx[rk[gx[i].rk]]=i;
	int tt=0; 
	for(int i=1;i<=(k+1)*n;i++)
		if(bx[i])
			gx3[++tt]=gx[bx[i]];
	for(int i=1;i<=tt;i++)
		gx[i]=gx3[i];
//	for(int i=1;i<=tot;i++)
//		cout<<gx[i].u<<" "<<gx[i].v<<" "<<gx[i].w<<" "<<gx[i].id<<" "<<gx[i].rk<<" "<<rk[gx[i].rk]<<" NxtSort\n";
//	cout<<"\n";
}
void MST()
{
	ll sum=0;int tot=tx;
	for(int i=0;i<(int)vx.size();i++)
		sum+=c[vx[i]];
//	for(int i=0;i<(int)vx.size();i++)
//		cout<<vx[i]<<" ";
//	cout<<"Choose\n";
//	cout<<sum<<" "<<ans<<"\n";
	if(sum>=ans)
		return;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=0;i<(int)vx.size();i++)
		for(int j=1;j<=n;j++)
			gx[++tot]={i+n+1,j,wx[vx[i]][j],n+1,vx[i]*n+j};
	mk(tot);
	for(int i=1;i<=tot;i++)
		if(find(gx[i].u)!=find(gx[i].v))
		{
			fa[find(gx[i].u)]=find(gx[i].v);
			sum+=gx[i].w;
			if(sum>=ans)
			{
				for(int j=1;j<=tot;j++)
					if(gx[j].id<=n)
						gx2[gx[j].id]=gx[j];
				for(int j=1;j<=n;j++)
					gx[j]=gx2[j];
				return;
			}
		}
	for(int j=1;j<=tot;j++)
		if(gx[j].id<=n)
			gx2[gx[j].id]=gx[j];
	for(int j=1;j<=n;j++)
		gx[j]=gx2[j];
//	for(int i=0;i<(int)vx.size();i++)
//		cout<<vx[i]<<" ";
//	cout<<"Choose\n";
//	cout<<sum<<"\n";
	ans=(ans>sum?sum:ans);
}
signed main()
{
//	freopen("road4.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<(&st-&en)/1024.0/1024.0<<"\n";
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>wx[i][j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
		if(find(a[i].u)!=find(a[i].v))
		{
			gx[++tx]=a[i];
			gx[tx].id=++id,gx[tx].rk=id;
			pre[++tot2]={gx[tx].w,id};
			fa[find(a[i].u)]=find(a[i].v);
			ans+=a[i].w;
		}
	init();
	for(int i=1;i<(1<<k);i++)
	{
		vx.clear();
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1)))
				vx.push_back(j);
		MST();
	}
	cout<<ans;
	return 0;
}
