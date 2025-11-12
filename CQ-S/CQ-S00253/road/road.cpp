#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fr first
#define sc second
#define pq priority_queue
#define gr greater
#define mkp make_pair
using ll=long long;
using db=double;
using pii=pair<int,int>;

const int N=2e6+5;
int n,m,nm,k,a[15][N],fa[N];
struct Edge{
	int u,v,w;
}e[N],ne[N],edge[N];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool _union(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) cin>>a[i][j];
	
	sort(e+1,e+m+1,[](Edge x,Edge y){
		return x.w<y.w;
	});
	ll ans=1e18;
	for(int msk=0;msk<(1<<k);msk++){
		int cnt=0;
		ll res=0;
		nm=0;
		for(int i=1;i<=k;i++){
			if(msk>>(i-1)&1){
				res+=a[i][0],cnt++;
				for(int j=1;j<=n;j++) ne[++nm]={cnt+n,j,a[i][j]};
			}
		}
		sort(ne+1,ne+nm+1,[](Edge x,Edge y){
			return x.w<y.w;
		});
		int p1=1,p2=1,tot=1;
		while(p1<=m&&p2<=nm){
			if(e[p1].w<ne[p2].w) edge[tot++]=e[p1++];
			else edge[tot++]=ne[p2++];
		}
		while(p1<=m) edge[tot++]=e[p1++];
		while(p2<=nm) edge[tot++]=ne[p2++];
		for(int i=1;i<=n+cnt;i++) fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(_union(edge[i].u,edge[i].v))
				res+=edge[i].w;
		}
		ans=min(ans,res);
	}
	
	cout<<ans<<'\n';
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
//	cin>>T;
    while(T--) solve();
    return 0;
}
