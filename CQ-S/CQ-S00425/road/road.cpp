#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
#define PII pair<int,int>
#define tp tuple<long long,int,int>
#define fi(x) (x.first)
#define se(x) (x.second)
int n,m,k,x,y,fa[10005],sum[15][10005];
long long z,ans,a[15],res=1e18;
tp g[2000005],edg[2000005];
vector<pair<int,long long> > edge[20005];
int found(int rt){
	if(fa[rt]==rt) return rt;
	return fa[rt]=found(fa[rt]);
}
void merge(int rt1,int rt2){
	int fa1=found(rt1),fa2=found(rt2);
	fa[fa1]=fa2;
}
void init_tree(int ssum){
	sort(edg+1,edg+m+ssum*n+1);
	for(int i=1;i<=m+ssum*n;i++){
		int siz=get<2>(edg[i]),fro=get<0>(edg[i]),to=get<1>(edg[i]);
		if(found(fro)!=found(to)){
			merge(fro,to);
			ans+=siz;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	I n >> m >> k;
	for(int i=1;i<=m;i++){
		I x >> y >> z;
		edge[x].push_back(make_pair(y,z));
		edge[y].push_back(make_pair(x,z));
		g[i]=make_tuple(x,y,z);
	}
	for(int i=1;i<=k;i++){
		I a[i];
		for(int j=1;j<=n;j++) I sum[i][j];
	}
	for(int i=0;i<=(1<<k);i++){
		int bit=i,ssum=0;
		for(int j=1;j<=m;j++){
			edg[j]=g[j];
		}
		int tot=m;
		for(int j=1;j<=k;j++){
			if(bit%2==1){
				for(int kk=1;kk<=n;kk++) edg[++tot]=make_tuple(sum[j][kk],n+j,kk),edg[++tot]=make_tuple(sum[j][kk],kk,n+j);
				ssum++;
			}
			bit>>=1;
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		init_tree(ssum);
		res=min(res,ans);
	}
	O res;
	return 0;
}
