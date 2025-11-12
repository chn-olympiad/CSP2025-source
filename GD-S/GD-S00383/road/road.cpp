#include <bits/stdc++.h>
#define int long long
using namespace std;
struct tu{int u,v,w,vis;}a[2000005];
int n,m,k,fa[2000005],cnt,ans,sum,fl[105],c[105];
bool cmp(tu x,tu y){return x.w<y.w;}
int fi(int x){
	if(fa[x]==x) return x;
	return fa[x]=fi(fa[x]);
}
void kruskal(){
	sort(a+1,a+cnt+1,cmp);
	for(int i=1,u,v,res=0,co=0;i<=cnt;i++){
		u=fi(a[i].u),v=fi(a[i].v);
		if(u==v) continue;
		fa[u]=v;
		ans+=a[i].w;
//		cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<'\n';
		if(a[i].vis) fl[a[i].vis]?co=co:co++,fl[a[i].vis]++;
//		cout<<co<<'\n';
		res++;
//		cout<<"res:"<<res<<' '<<co+n<<'\n';
		if(res>=co+n-1) break;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=2*n+2*k;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		a[++cnt]={u,v,w,0};
	}
	for(int i=1,x;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			a[++cnt]={i+n,j,c[i]+x,i};
		}
	}
	kruskal();
//	for(int i=1;i<=cnt;i++) cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<' '<<a[i].vis<<'\n';
	for(int i=1;i<=k;i++){
//		cout<<fl[i]<<' '<<vs[i]<<'\n';
		if(fl[i]>1) ans-=(fl[i]-1)*c[i];
	}
	cout<<ans;
	return 0;
}
/*
4 1 2
1 4 114
1 8 8 8 8
25 0 0 0 0
*/
