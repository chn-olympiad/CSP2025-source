#include<bits/stdc++.h>
using namespace std;//2^k * (nk + n)log()
//T1>>T2
const int N = 11000,M = 1100000;
int n,m,k;
struct edge{
	int u,v,w;
}e[M],e2[M];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
struct unionset{
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i] = i;
		}
	}
	int find(int x){
		if(fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
}us,us2;
int ok[N];
int cnt = 0;
int a[30][N];
int c[30];
int op[30];
long long ans = 0;
long long uwu = 0;
long long wmin = 1e9+7;
long long dfs(int x){
//	cout<<x<<endl;
	if(x<=k){	
		op[x] = 1;
		long long an = dfs(x+1);
		op[x] = 0;
		an = min(an,dfs(x+1));
		return an;
	}
	long long ans1 = 0;
	int cbt = 0;
	for(int i=1;i<=k;i++){
		if(op[i]){
			ans1 += c[i];
			for(int j=1;j<=n;j++){
				if(a[i][j]>wmin)continue;
				e2[++cbt] = {n+i,j,a[i][j]};
			}
		}
	}
//	if(ans1>uwu)return ans1;
	
	for(int i=1;i<=cnt;i++){
		e2[++cbt] = e[ok[i]];
	}
	sort(e2+1,e2+cbt+1,cmp);
	us2.init(n+100);
	for(int i=1;i<=cbt;i++){
		int x = e2[i].u,y = e2[i].v;
		if(us2.find(x)!=us2.find(y)){
			us2.fa[us2.find(x)] = us2.find(y);
			ans1+=e2[i].w;
		}
	}
//	uwu = min(uwu,ans1);
	return ans1;
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	double xx = clock();
	cin>>n>>m>>k;
	us.init(n+100);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u = u,e[i].v = v,e[i].w = w;
	}	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		}
	}
//	cerr<<"read_done"<<endl;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x = e[i].u,y = e[i].v;
		if(us.find(x)!=us.find(y)){
			us.fa[us.find(x)] = us.find(y);
			ans += e[i].w;
			ok[++cnt] = i;
			wmin = max(wmin,(long long)e[i].w);
		}
	}
//	cout<<"1"<<endl;
	uwu = ans;
	ans = min(ans,dfs(1));
	cout<<ans<<endl;
	return 0;
}
