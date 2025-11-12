#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10050,M=1000010;
int n,m,k;
struct edge{
	int u,v,w;
	friend bool operator <(const edge a,const edge b){return a.w<b.w;}
};
vector<edge> E,e;
int fa[N],siz[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int tot;
int c[12],a[12][N];
int cst1;
int kruskal(vector<edge> d){
	int res=0,cnt=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=n;i++) siz[i]=1;
	for(auto i:d){
		int fu=find(i.u),fv=find(i.v);
		if(fu==fv) continue;
		fa[fu]=fv;siz[fv]+=siz[fu];siz[fu]=0;
		cnt++;res+=i.w;
		//cout<<i.u<<' '<<i.v<<' '<<i.w<<' '<<siz[fv]<<'\n';
		if(tot==0) E.push_back({i.u,i.v,i.w});
		if(siz[fv]==n) break;
	}
	return res;
}
bool all0=true;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end());
	tot=kruskal(e);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) all0=false;
		for(int j=1;j<=n;j++){cin>>a[i][j];}
	}
	if(k==0){cout<<tot;return 0;}
	//for(auto i:E){cout<<i.u<<' '<<i.v<<' '<<i.w<<'\n';}
	int mn=1e17,msk=0;
	if(all0) msk=(1<<k)-1;
	int cst1,cst2,i,j;
	for(;msk<(1<<k);msk++){
		e=E;cst1=0;
		for(i=1;i<=k;i++){
			if((msk>>(i-1))&1){
				cst1+=c[i];
				for(j=1;j<=n;j++){e.push_back({i+n,j,a[i][j]});}
			}
		}
		sort(e.begin(),e.end());
		cst2=kruskal(e);
		//for(auto i:e){cout<<i.u<<' '<<i.v<<' '<<i.w<<'\n';}puts("");
		//cout<<msk<<' '<<cst1<<' '<<cst2<<' '<<cst1+cst2<<'\n';
		mn=min(mn,cst1+cst2);
	}
	cout<<mn;
	return 0;
}
