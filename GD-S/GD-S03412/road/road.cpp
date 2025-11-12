#include <bits/stdc++.h>
using namespace std;

struct stu{
	int u,v,w,op;
	bool operator < (stu o)const{
		return w<o.w;
	}
}e[1000007];
int n,m,k;
int fa[100007],siz[100007];
vector<stu> E;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
}
bool link(int u,int v){
	u=get(u),v=get(v);
	if(u==v) return 0;
	if(siz[u]>siz[v]) swap(u,v);
	fa[u]=v;
	siz[v]+=siz[u];
	return 1;
}
int c[17],a[17][100007];
signed main(){
	freopen("road.in" ,"r",stdin );
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]=(stu){u,v,w,0};
	}
	init();
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		if(link(e[i].u,e[i].v)) E.push_back(e[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			E.push_back((stu){i+n,j,a[i][j],i});
		}
	}
	sort(E.begin(),E.end());
	long long res=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++){
		int msk=(i<<1)|1;
		long long ans=0;
		for(int j=1;j<=k;j++) if(msk&(1<<j)) ans+=c[j];
		init();
		for(stu x:E){
			if(msk&(1<<x.op)) if(link(x.u,x.v)){
				//cerr<<" "<<x.w<<endl;
				ans+=x.w;
			}
		}
		res=min(res,ans);
		//cerr<<msk<<" "<<ans<<endl;
	}
	cout<<res<<endl;
	return 0;
} 
