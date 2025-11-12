#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vint;
typedef vector<pii>vpii;
const ll inf=0x3f3f3f3f3f3f3f3f;

const int N=10020,M=1000010;
int n,m,k;
struct node{
	int a,b,w;
}e[M],e2[N],e3[N*10];
int c2;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N],sz[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
vpii el[10];
int av[10];
ll ans=inf;
void solve(int l,int r){
	if(l==r) return ;
	int mid=(l+r)/2;
	solve(l,mid),solve(mid+1,r);
	inplace_merge(e3+(l-1)*n+1,e3+mid*n+1,e3+r*n+1,cmp);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i,sz[i]=1;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int p=find(e[i].a),q=find(e[i].b);
		if(p!=q){
			if(sz[p]>sz[q]) swap(p,q);
			fa[p]=q;
			sz[q]+=sz[p];
			e2[++c2]=e[i];
		}
	}
	for(int i=0;i<k;i++){
		scanf("%d",&av[i]);
		el[i].resize(n);
		for(int j=0;j<n;j++){
			scanf("%d",&el[i][j].fi);
			el[i][j].se=j+1;
		}
		sort(el[i].begin(),el[i].end());
	}
	for(int j=0;j<(1<<k);j++){
		ll s=0;
		int c3=0,cc=0;
		for(int i=0;i<k;i++)
			if(j>>i&1) {
				s+=av[i];
				cc++;
				for(int l=0;l<n;l++)
					e3[++c3]={n+cc,el[i][l].se,el[i][l].fi};
			}
		for(int i=1;i<=n+cc;i++){
			fa[i]=i,sz[i]=1;
		}
		if(cc>0) solve(1,cc);
		int d2=1,d3=1,siz=n+cc;
		while(siz>1){
			if(d2<=c2&&(d3>c3||e2[d2].w<=e3[d3].w)){
				int p=find(e2[d2].a),q=find(e2[d2].b);
				if(p!=q){
					if(sz[p]>sz[q]) swap(p,q);
					fa[p]=q;
					sz[q]+=sz[p];
					s+=e2[d2].w;
					siz--;
				}
				d2++;
			}else{
				int p=find(e3[d3].a),q=find(e3[d3].b);
				if(p!=q){
					if(sz[p]>sz[q]) swap(p,q);
					fa[p]=q;
					sz[q]+=sz[p];
					s+=e3[d3].w;
					siz--;
				}
				d3++;
			}
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/