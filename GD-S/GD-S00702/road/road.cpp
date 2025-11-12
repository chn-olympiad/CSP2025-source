#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y,z,ti;
};
bool cp(edge x,edge y){
	return x.z<y.z;
}
int n,m,k,c[15],a[15][10010],bj[10010],val[15][100010];
int fa[10010],siz[10010];
long long ans;
edge e[1000010];
vector<edge> g;
vector<int> vc[15];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(siz[x]<siz[y])swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+m+1,cp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y;
		x=find(x);
		y=find(y);
		if(x==y)continue;
		g.push_back(e[i]);
		merge(x,y);
		ans+=e[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int st=0;st<=(1<<k)-1;st++)
	{
		long long s=0;
		vector<int> cl;
		for(int i=1;i<=k;i++)
		{
			if(st&(1<<(i-1)))
			{
				s+=c[i];
				cl.push_back(i);
				vc[i].clear();
			}
		}
		for(int i=1;i<=n;i++)
		{
			int mi=0x3f3f3f3f;
			for(int j:cl)
				mi=min(mi,a[j][i]);
			for(int j:cl)
			{
				if(mi==a[j][i])
				{
					vc[j].push_back(i);
					bj[i]=j;
					break;
				}
			}
			s+=mi;
		}
		vector<edge> te;
		for(int i:cl)
		{
			for(int j:cl)
			{
				if(i==j)continue;
				int mi=0x3f3f3f3f,ti=0;
				for(int x:vc[j])
				{
					if(a[i][x]<mi)
					{
						mi=a[i][x];
						ti=x;
					}
				}
				te.push_back((edge){i,j,mi,ti});
			}
		}
		sort(te.begin(),te.end(),cp);
		for(int i:cl)
		{
			fa[i]=i;
			siz[i]=1;
		}
		for(edge ve:te)
		{
			int x=ve.x,y=ve.y;
			int xx=find(x),yy=find(y);
			if(xx==yy)continue;
			vc[x].push_back(ve.ti);
			merge(xx,yy);
			s+=ve.z;
		}
		ans=min(ans,s);
	}
	printf("%lld",ans);
	return 0;
}
