#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
	int u,v,w;
}e[1000005];
int fa[10005],n,m,k;
long long ans;
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int find(int x){
	return fa[x] == x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)] = find(y);
}
void kru(){
	int cnt = 0;
	for (int i = 1;i<=m;i++){
		int x = find(e[i].u);
		int y = find(e[i].v);
		if (x != y){
			merge(x,y);
			ans += e[i].w;
			cnt++;
			if (cnt == n-1) return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i<=n;i++){
		fa[i] = i;
	}
	for (int i = 1;i<=m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		// e[i+m] = e[i];
	}
	sort(e+1,e+1+m,cmp);
	kru();
	cout << ans << endl;
	return 0;
}