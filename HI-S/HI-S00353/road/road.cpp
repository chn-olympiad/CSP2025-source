#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e4+20,K=20;
ll n,m,k,answer=1e18;
int b=0,pc=0,oo;
struct Edge{
	ll u,v,w;
	bool operator < (const Edge a) const{
		return v<a.v;
	}
	bool operator > (const Edge a) const{
		return v>a.v;
	}
};
vector<Edge> tmp,e;
bool cm(Edge a,Edge b){
	return a.w<b.w;
}
bool cmp(Edge a,Edge b){
	int x=a.v,y=b.v;
	if(((x-n)<=pc)&&((y-n)<=pc)) return a.w<b.w;
	else{
		return a<b;
	}
}
ll c[K],a[K][N];
struct DSU{
	int f[N];
	void init(){
		for(int i = 1;i<=n+k;i++) f[i]=i;
	}
	int find(int u){
		if(f[u]==u) return u;
		else return f[u]=find(f[u]);
	}
	void merge(int u,int v){
		int x=find(u);
		int y=find(v);
		if(x!=y){
			f[x]=y;
		}
	}
} dsu;
ll oomst(){
	int cnt=n-1,p=-1;
	dsu.init();
	while(cnt){
		p++;
		Edge x=tmp[p];
		int u=x.u,v=x.v;
		if(dsu.find(u)!=dsu.find(v)){
			dsu.merge(u,v);
			cnt--;
		}
	}
	return p;
}
ll mst(int no){
	int cnt=no-1,p=-1;
	ll ans=0;
	dsu.init();
	while(cnt){
		p++;
		Edge x=e[p];
		ll u=x.u,v=x.v,w=x.w;
		if(dsu.find(u)!=dsu.find(v)){
			dsu.merge(u,v);
			ans+=w;
			cnt--;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(ll i = 1,u,v,w;i<=m;i++){
		cin >> u >> v >> w;
		tmp.push_back({u,v,w});
	}
	sort(tmp.begin(),tmp.end(),cm);
	oo=oomst();
	for(int i = 0;i<=oo;i++){
		auto x=tmp[i];
		e.push_back({x.u,x.v,x.w});
	}
	for(int i = 1;i<=k;i++){
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
			e.push_back({j,n+i,a[i][j]});
		}
	}
	for(;b<(1<<k);b++){
		ll add=0;
		pc=0;
		for(int t = 0;t<k;t++){
			if(b&(1<<t)){
				pc++;
				add+=c[t+1];
			}
		}
		sort(e.begin(),e.end(),cmp);
		answer=min(answer,mst(n+pc)+add);
	}
	cout << answer << endl;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

