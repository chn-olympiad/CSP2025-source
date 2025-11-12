#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u , v , w;
}a[100005];
long long n , m , fa[10005] , k , ans;
long long find(long long x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
bool cmp(edge A , edge B){
	return A.w < B.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k==0){
		for(int i=1;i<=n;i++)fa[i] = i;
		for(int i=1;i<=m;i++){
			int u , v , w;cin >> u >> v >> w;
			a[i] = {u,v,w};
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u = find(a[i].u) , v = find(a[i].v);
			if(u!=v)fa[v] = u , ans += a[i].w;
		}
		cout << ans;
	}else cout << 0;
	return 0;
}

