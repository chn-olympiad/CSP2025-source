#include<bits/stdc++.h>
#define endl '\n'
#define PII pair<int,int>
#define qaq cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
typedef long long ll;
const int M = 2e6+10+2e5;
const int N = 1e5+10;
struct dt{
	int u,v;
	ll w;
	bool flag;
	friend bool operator<(const dt &q,const dt &p){
		return q.w<p.w;
	}
}e[M];
int fa[N];
int n,m,k;
int ecnt;
ll c[N];
bitset<N> fq;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		fa[u]=v;
	}
}
inline void add(int u,int v,int w,bool flag){
	e[++ecnt]=(dt){u,v,w,flag};
	return;	
}
inline ll solve(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+ecnt);
	ll ans=0;
	for(dt E:e){
		int u=E.u;
		int v=E.v;
		ll w=E.w;
		bool flag=E.flag;
		if(find(u)!=find(v)){
			ans+=w;
			merge(u,v);
		}
	}
	return ans;
}
int main(){
	qaq;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;
		add(u,v,w,0);
		add(v,u,w,0); 
	}
	for(int i=1;i<=k;i++){
		int u=i+n;
		ll k;
		cin >> k;
		for(int v=1;v<=n;v++){
			ll o;
			cin >> o;
			add(v,u,0,0);
			add(u,v,0,0);
		}
	}
	cout << solve() << endl;
	return 0;
}

//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

