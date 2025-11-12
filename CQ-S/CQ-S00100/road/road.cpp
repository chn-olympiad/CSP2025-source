#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int N=2e4+12;
const int M=2e6+12;
const int MX=3e7;
int n,m,k;
struct edge{
	int fr,to,val;
}e[M],E[M];
bool cmp(edge a,edge b){
	return a.val<b.val;
}
int a[12][N],c[12];
struct dsu{
	int fa[N];
	int siz[N];
	dsu(){}
	dsu(int n){
		for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	}
	inline void init(int n){
		for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	}
	inline int find(int x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	inline bool merge(int a,int b){
		a=find(a),b=find(b);
		if(a==b)return false;
		if(siz[a]>siz[b]){
			fa[b]=a;
			siz[a]+=siz[b];
		}else{
			fa[a]=b;
			siz[b]+=siz[a];
		}
		return true;
	}
}bcj;
void Do_A(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m]={i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	bcj.init(n+k);
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(bcj.merge(e[i].fr,e[i].to)){
			ans+=e[i].val;
		}
	}
	cout<<ans;
}
//int head[N],to[M],nex[M],val[M],tot=0;
//inline void mkr(int u,int v,int w){
//	to[++tot]=v;
//	nex[tot]=head[u];
//	val[tot]=w;
//	head[u]=tot;
//}
//void dfs(int bg,int now,int Fa,int vl){
//	dis[bg][now]=dis[bg][Fa]+vl;
//	for(int f=head[now];f;f=nex[f]){
//		int t=to[f];
//		if(t!=Fa){
//			dfs(t,now);
//		}
//	}
//}
bool ff[12]={0};
inline ll Do_Solve(){
	ll fans=0;
	int tot=0;
	int nrd=m;
	for(int i=1;i<=m;i++){
		E[i]=e[i];
	}
//	for(int i=1;i<=nrd;i++){
//		cout<<"E "<<e[i].fr<<' '<<e[i].to<<' '<<e[i].val<<endl;
//	}
	for(int i=1;i<=k;i++){
		if(ff[i]){
			tot++;
			fans+=c[i];
//			cout<<"+ "<<c[i]<<endl;
			for(int j=1;j<=n;j++){
				E[++nrd]={n+tot,j,a[i][j]};
//				cout<<"P "<<nrd<<endl;
			}
		}
	}
//	cout<<"fans ="<<fans<<endl;
//	for(int i=1;i<=nrd;i++){
//		cout<<"E "<<e[i].fr<<' '<<e[i].to<<' '<<e[i].val<<endl;
//	}
	sort(E+1,E+nrd+1,cmp);
	bcj.init(n+tot);
	for(int i=1;i<=nrd;i++){
		if(bcj.merge(E[i].fr,E[i].to)){
//			cout<<"e[i].val="<<E[i].val<<endl;
			fans+=E[i].val;
		}
	}
//	cout<<"fans ="<<fans<<endl;
	return fans;
}
void Do_B(){
//	int tim=0;
	ll ans=1e18;
	while(clock()<=850000){
		for(int i=1;i<=k;i++){
			ff[i]=(rand()&1);
		}
		ans=min(ans,Do_Solve());
//		tim++;
//		cout<<"_--\n";
//		cout<<ans<<endl;
	}
	for(int i=1;i<=k;i++){
		ff[i]=0;
	}
	ans=min(ans,Do_Solve());
	for(int i=1;i<=k;i++){
		ff[i]=1;
	}
	ans=min(ans,Do_Solve());
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].fr>>e[i].to>>e[i].val;
	}
	bool flag_A=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag_A=false;
		bool tmp=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)tmp=true;
		}
		if(!tmp)flag_A=false;
	}
	if(flag_A||k==0){
		Do_A();
		return 0;
	}
	Do_B();
	return 0;
} 
