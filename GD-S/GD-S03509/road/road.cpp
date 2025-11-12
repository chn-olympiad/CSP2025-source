#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,tot;
ll c[11];
struct edge{
	int u,v;
	ll w;
} e[1000010],et[100010];
int fa[10010];
//vector<edge> ep[11];
edge ep[11][10010];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return ;
	fa[fx]=fy;
	return ;
}
int len,tlen;
edge eu[200010],tmp[200010];
void work(int id){
	int p=1,q=0;
	tlen=0;
	while(p<=len||q<=n){
		if(p>len) tmp[++tlen]=ep[id][q++];
		else if(q>n) tmp[++tlen]=eu[p++];
		else{
			if(eu[p].w<=ep[id][q].w) tmp[++tlen]=eu[p++];
			else tmp[++tlen]=ep[id][q++];
		}
	}
	len=tlen;
	for(int i=1;i<=tlen;i++) eu[i]=tmp[i];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	clock_t st=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ll aa;
			cin>>aa;
			ep[i][j]=(edge){n+i,j,aa}; 
		}
		sort(ep[i]+1,ep[i]+1+n,[](edge aa,edge bb){
			return aa.w<bb.w;
		});
	}
	sort(e+1,e+1+m,[](edge aa,edge bb){
		return aa.w<bb.w;
	});
	for(int i=1;i<=n;i++) fa[i]=i;
	ll ans=0ll;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
		et[++tot]=e[i]; 
	}
	for(int j=1;j<(1ll<<k);j++){
		ll num=0ll;
		bitset<11> sel(j);
		len=n-1;
		for(int i=1;i<=tot;i++) eu[i]=et[i];
		for(int i=1;i<=k;i++){
			if(sel[i-1]==0) continue;
			work(i);
			num+=c[i];
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int cnt=0;
		for(int i=1;i<=len;i++){
			if(find(eu[i].u)==find(eu[i].v)) continue;
			num+=eu[i].w;
			cnt++;
			if(cnt==n+k-1) break;
			merge(eu[i].u,eu[i].v);
		}
		ans=min(ans,num);
	}
	cout<<ans;
//	clock_t en=clock();
//	cout<<'\n'<<(double)(1.0*(en-st)/CLOCKS_PER_SEC);
	return 0;
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
