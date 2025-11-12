#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int K = 15;
int n,m,k;
long long ans = 1e18;
struct node{
	int u,v,w;
};
vector<node> E;
vector<node> E2;
int a[K][N];
int fa[N];
int bk[K];
int read(){
	int res = 0;
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9'){
		res = res*10+ch-'0';
		ch = getchar();
	}
	return res;
}
bool cmp(node a, node b){
	return a.w < b.w;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
long long MST(){
	long long res = 0;
	sort(E2.begin(), E2.end(), cmp);
	for(int i = 1; i <= n+15; i++) fa[i] = i;
	
	for(int i1 = 0, i2 = 0;;){
		if(i1 >= (int)E.size() && i2 >= (int)E2.size()) break;
		
		int i,flag;
		if(i1 >= (int)E.size()) i = i2, flag = 2;
		else if(i2 >= (int)E2.size()) i = i1, flag = 1;
		else if(E[i1].w <= E2[i2].w) i = i1, flag = 1;
		else i = i2, flag = 2;
		
		if(flag == 1){
			if(find(E[i].u) != find(E[i].v)){
				res += E[i].w;
				fa[find(E[i].u)] = find(E[i].v);
			}
			i1++;
		}else{
			if(find(E2[i].u) != find(E2[i].v)){
				res += E2[i].w;
				fa[find(E2[i].u)] = find(E2[i].v);
			}
			i2++;
		}
		
		if(res > ans) return 1e18;
	}
	return res;
}
int lowbit(int x){
	return x&(-x);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1, u,v,w; i <= m; i++){
		u = read(), v = read(), w = read();
		E.push_back({u,v,w});
	}
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++)
			a[i][j] = read();
	
	sort(E.begin(), E.end(), cmp);
	int S = (1 << k);
	for(int i = 0; i < S; i++){
		long long tmp = 0;
		E2.clear();
		for(int j = 0; j < k; j++){
			if((i >> j)&1){
				tmp += a[j+1][0];
				if(tmp > ans){
					tmp = -1;
					break;
				}
				for(int o = 1; o <= n; o++)
					E2.push_back({n+j+1, o, a[j+1][o]});
			}
		}
		if(tmp == -1) continue;
		tmp += MST();
		
		if(ans > tmp){
			ans = tmp;
		}
		else{
			i += lowbit(i);
		}
	}
	
	cout << ans;
	return 0;
}
