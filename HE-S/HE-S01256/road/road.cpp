bool stp;
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,ans;
int fa[(int)5e5];
int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
struct eee{int u,v,w;}E[(int)2e6];
bool cmp(eee x,eee y){return x.w<y.w;}
vector<pair<int,int> >e[(int)5e6];
void add(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}int w[(int)2e5];
int dfn[(int)5e5],id[(int)5e5],tot,siz[(int)2e5];
void dfs(int nw,int F){
	fa[nw]=F;siz[nw]=1;
	dfn[nw]=++tot,id[tot]=nw;
	for(auto x:e[nw]){
		int to=x.first,val=x.second;
		if(to==F)continue;w[to]=val;
		dfs(to,nw);siz[nw]+=siz[to];
	}
}
//struct ST{
//	int f[(int)2e5][17];
//	int lg[(int)5e5];
//	void build(){
//		lg[1]=0;
//		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1,f[i][0]=a[id[i]];
//		for(int i=1;i<=16;i++){
//			for(int j=1;j<=n-(1<<i)+1;j++){
//				f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
//			}
//		}
//	}
//	int query(int l,int r){
//		int k=lg[r-l+1],g=r-l+1-(1<<k);
//		return max(f[l][k],f[][lg[g]+1])
//	}
//};
int a[15][(int)5e4+10],c[(int)20];
struct seg{
	#define ls i<<1
	#define rs i<<1|1
	#define mid ((l+r)>>1) 
	int val[(int)5e5];
	void build(int i,int l,int r,int Id){
		if(l==r)return val[i]=a[Id][id[l]],void();
		build(ls,l,mid,Id),build(rs,mid+1,r,Id),val[i]=min(val[ls],val[rs]);
	}
	int query(int i,int l,int r,int x,int y){
		if(x>y)return 1e18;
		if(x<=l&&y>=r)return val[i];int ans=1e18;
		if(x<=mid)ans=min(ans,query(ls,l,mid,x,y));
		if(y>mid)ans=min(ans,query(rs,mid+1,r,x,y));
		return ans;
	}
}T[11];
int Ans=1e18;
int tim,num;
bool edp;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	cout<<(&edp-&stp)*1.0/1024/1024<<'\n';
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w;
	sort(E+1,E+m+1,cmp);for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int X=get(E[i].u),Y=get(E[i].v);
		if(X==Y)continue;fa[Y]=X;ans+=E[i].w;
		add(E[i].u,E[i].v,E[i].w); 
//		cout<<E[i].u<<' '<<E[i].v<<E[i].w<<'\n';
		cnt++;if(cnt==n-1)break;
	}if(k==0)return cout<<ans<<'\n',0;
	fa[1]=0,dfs(1,0);
//	for(int i=1;i<=n;i++)cout<<id[i]<<'\n';
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int sum=0;
//	if(k==5)return solve(),0;
//	for(int i=1;i<=n;i++)cout<<w[i]<<'\n';
//	cout<<ans<<'\n';
	for(int i=1;i<=k;i++)T[i].build(1,1,n,i);
	for(int S=0;S<(1<<k)-1;S++){
		sum=0;
		for(int j=1;j<=k;j++)if((S>>(j-1))&1)sum+=c[j];
//		cout<<sum<<'\n';
		for(int i=2;i<=n;i++){
			int Mi=1e18;
			for(int j=1;j<=k;j++){
				if((S>>(j-1))&1){
					Mi=min(Mi,T[j].query(1,1,n,dfn[i],dfn[i]+siz[i]-1)+
					min(T[j].query(1,1,n,1,dfn[i]-1),T[j].query(1,1,n,dfn[i]+siz[i],n)));
				}
			}sum+=min(Mi,w[i]);
//			cout<<i<<":"<<w[i]<<' '<<Mi<<'\n';
		}Ans=min(Ans,sum);
	}cout<<Ans<<'\n';
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4 
100 1 3 2 4
*/
