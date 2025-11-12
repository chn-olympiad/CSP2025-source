#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int n,m,k,c[15],a[15][10005],fa[10005],mn[10005][10],ans;
int sum[1<<10],cnt;
struct did{
	int x,y,z,id;
}ed[1000005],e[110005];
bool cmp(did a,did b){
	return a.z<b.z;
}
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>ed[i].x>>ed[i].y>>ed[i].z;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++cnt]={i+n,j,a[i][j],i};
		}
	}
	for(int i=1,fx,fy;i<=m;i++){
		fx=getfa(ed[i].x);
		fy=getfa(ed[i].y);
		if(fx!=fy){
			e[++cnt]=ed[i];
//			cout<<ed[i].x<<' '<<ed[i].y<<'\n';
			ans+=ed[i].z;
			fa[fx]=fy;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1,res=0;i<(1<<k);i++){
		res=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1))res+=c[j];
		}
		for(int j=1,fx,fy;j<=cnt;j++){
			if(e[j].id!=0&&(i&(1<<e[j].id-1))==0)continue;
			fx=getfa(e[j].x);
			fy=getfa(e[j].y);
			if(fx!=fy){
				fa[fx]=fy;
				res+=e[j].z;
			}
		}
//		cout<<i<<' '<<res<<'\n';
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}


