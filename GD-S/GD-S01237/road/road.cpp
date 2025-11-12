#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=10005;
const ll M=1000005;
const ll K=13;
ll n,m,k;
ll maxx;
ll ans=0,cnt,cnt2,addcost=0;
ll c[N],a[K][N],ma[N][N],d[N],id;
bool b[N];
ll fa[N];
struct note1 { 
	ll u,v,w;
} edge[N];
ll fin(int x) {
	if(fa[x]!=x) return fa[x]=fin(fa[x]);
	else return x;
}
bool cmp1(note1 a1,note1 a2) {
	return a1.w<a2.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,127,sizeof(d));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(ma,0,sizeof(ma));
	for(int i=1,a1,a2,a3; i<=m; i++) {
		cin>>a1>>a2>>a3;
		edge[i]= {a1,a2,a3};
		ma[a1][a2]=ma[a2][a1]=i;
	}


	if(k==0) {
		for(int i=1; i<=k; i++) {
			maxx=1e18;
			cin>>c[i];
			for(int j=1; j<=n; j++) {
				cin>>a[i][j];
				d[j]=min(d[j],a[i][j]);
			}
		}
		sort(edge+1,edge+m+1,cmp1);
		for(int i=1; i<=n; i++) fa[i]=i;
		ans=0,cnt=0,cnt2=0;
		while(cnt2<=m) {
			note1 ls=edge[++cnt2];
			if(fin(ls.u)!=fin(ls.v)) {
				fa[fin(ls.u)]=fin(ls.v);
				ans+=ls.w;
				if(++cnt==n-1)break;
			}
		}
		cout<<ans<<endl;
	} else {
		
		for(int i=1; i<=k; i++) {
			cin>>c[i];
			for(int j=1; j<=n; j++) {
				cin>>a[i][j];
				if(a[i][j]==0) id=j;
			}
			for(int j=1;j<=n;j++){
				if(j==id) continue;
				if(ma[j][id]==0) {
					edge[++m]={id,j,a[id][j]};
					ma[id][j]=ma[j][id]=m;
				}
				else edge[ma[j][id]].w=min(edge[ma[j][id]].w,a[i][j]); 
			}
		}
		for(int i=1; i<=n; i++) fa[i]=i;
		sort(edge+1,edge+m+1,cmp1);
		cnt2=0;
		while(cnt2<=m) {
			note1 ls=edge[++cnt2];
			if(fin(ls.u)!=fin(ls.v)) {
				fa[fin(ls.u)]=fin(ls.v);
				ans+=ls.w;
				if(++cnt==n-1)break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
