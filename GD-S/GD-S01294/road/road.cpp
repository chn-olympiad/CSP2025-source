#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
int n,m,k;
struct edge{
	int u,v;
	long long w;
}a[M];
bool cmp(edge a,edge b){
	return a.w < b.w;
}
vector<int> e[15];
int c[K];
int aa[K][N];
int t[K];
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy){
		return 0;
	}
	fa[fx] = fy;
	return 1;
}
long long ans;
int kruskal(){
	int cnt = 0;
	sort(a + 1,a + m + 1,cmp);
	for(int i = 1;i <= m;i++){
		if(merge(a[i].u,a[i].v)){
			ans += a[i].w;
			cnt++;
		}
		if(cnt >= n - 1) return ans;
	}
	return ans;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
			
	}
	for(int i = 1;i <= N;i++){
		fa[i] = i;
	}
	bool fa = 1;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i] != 0) fa = 0;
		int tmp = 0;
		for(int j = 1;j <= n;j++){
			cin >> aa[i][j];
			if(aa[i][j] == 0){
				tmp = 1;
				t[i] = j;
			}
		}
		if(tmp == 0) fa = 0;
	}
	if(fa){
		//cout << "fa" << endl;
		for(int i = 1;i <= k;i++){
			for(int j = 1;j <= n;j++){
				if(j == t[i]) continue;
				a[++m] = {t[i],j,aa[i][j]};
			}
		}
		cout << kruskal() << endl;
		return 0;
	}
	if(k == 0){
		cout << kruskal() << endl;
		return 0;
		
	}
	cout << kruskal() << endl;
	return 0;
}
