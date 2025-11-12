#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[1000005],siz[1000005],c[1000005],id[15];
struct edge{int x,y,w;}a[1000005],b[15][1000005];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void unionn(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(siz[fx]>siz[fy]) swap(fx,fy);
	fa[fx]=fy;return;
}
vector<int> v;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) fa[i]=i,siz[i]=1;
	for(int i=1; i<=m; i++) cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+m+1,cmp);
	long long mini=0,cnt=0;
	for(int i=1; i<=m; i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy) unionn(fx,fy),b[0][++cnt]=a[i],mini+=a[i].w;
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++) b[i][j].x=n+i,b[i][j].y=j,cin>>b[i][j].w;
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	for(int S=0; S<(1ll<<k); S++){
		int nwcnt=0;
		for(int i=0; i<=k; i++) id[i]=1;
		long long nws=0;
		for(int i=1; i<=n+k; i++) fa[i]=i,siz[i]=1;
		v.clear(),v.push_back(0);
		for(int j=1; j<=k; j++) if((S>>j-1)&1ll) nws+=c[j],nwcnt++,v.push_back(j);
		for(int i=1; i<=n+nwcnt-1; i++){
			for(int j:v) while(id[j]<=n&&find(b[j][id[j]].x)==find(b[j][id[j]].y)) id[j]++;
			long long mn=(long long)1e18,pos=0;
			for(int j:v) if(mn>b[j][id[j]].w) mn=b[j][id[j]].w,pos=j;
			nws+=mn,unionn(b[pos][id[pos]].x,b[pos][id[pos]].y),id[pos]++;
		}
		mini=min(mini,nws);
	}
	cout<<mini;
	return 0;
}