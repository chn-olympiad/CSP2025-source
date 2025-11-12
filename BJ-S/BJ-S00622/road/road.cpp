#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+19;
const int N = 1e6+19;
struct node{
	long long id,k;
};
struct node1{
	long long x,y,k;
}a[N];
long long fa[N],n,m,k,ans;
vector<node> v[maxn];

bool cmp(node1 x,node1 y){
	return x.k<y.k;
}
int find(int x){
	if(fa[x] == x) return x;
	return find(fa[x]);
}
void add(int x,int y){
	if(find(x)>find(y)) fa[find(x)] = find(y);
	else fa[find(y)] = find(x);
}
void prim(){
	for(int i = 1;i<=m+k*n;i++){
		if(find(a[i].x) != find(a[i].y)){
			add(a[i].x,a[i].y);
			ans+=a[i].k;
		}
	}
}
void solve(){
	cin>>n>>m>>k;
	for(int i = 1;i<=n+k;i++) fa[i] = i;
	for(int i = 1;i<=m;i++){
		long long x,y,vi;
		cin>>x>>y>>vi;
		v[x].push_back({y,vi});
		v[y].push_back({x,vi});
		a[i].x = x;
		a[i].y = y;
		a[i].k = vi;
	}
	for(int i = 1;i<=k;i++){
		long long vk;
		cin>>vk;
		for(int j = 1;j<=n;j++){
			long long vi;
			cin>>vi;
			v[j].push_back({n+i,vi});
			v[j].push_back({n+i,vi});
			a[m+j].x = n+i;
			a[m+j].y = j;
			a[m+j].k = vi;
		}
	}
	sort(a+1,a+m+k*n+1,cmp);
	prim();
	cout<<ans;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t = 1;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
