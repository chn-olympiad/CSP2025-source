#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u, v, w;
}ma[1000007];
struct edge{
	int c, a[10007];
}ma1[17];
int n, m, k;
int cmp(node a, node b){
	return a.w < b.w;
}
int fa[10007];
int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
int kl(){
	int ans = 0;
	sort(ma + 1, ma + m + 1, cmp);
	for(int i = 1;i <= n;++i){
		fa[i] = i;
	}
	int tot = 0;
	for(int i = 1;i <= m;++i){
		if(tot == n - 1){
			break;
		}
		if(find(ma[i].u) != find(ma[i].v)){
			ans += ma[i].w;
			tot++;
			fa[find(ma[i].u)] = fa[find(ma[i].v)];
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++i){
		cin >> ma[i].u >> ma[i].v >> ma[i].w;
	}
	for(int i = 1;i <= k;++i){
		cin >> ma1[i].c;
		for(int j = 1;j <= n;++j){
			cin >> ma1[i].a[j];
		}
	}
	if(k == 0){
		cout << kl();
		return 0;
	}else{
		for(int j = 1;j <= k;++j){
			for(int i = 1;i <= m;++i){
				if(ma1[j].a[ma[i].u] + ma1[j].a[ma[i].v] < ma[i].w){
					ma[i].w = ma1[j].a[ma[i].u] + ma1[j].a[ma[i].v];
				}
			}
		}
		cout << kl();
		return 0;
	}
}
