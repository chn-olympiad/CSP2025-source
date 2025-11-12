#include<bits/stdc++.h>
using namespace std;
int n , m , k , m1 , sum , mn = 1e9 , bs;
long long cnt;
struct l{
	int u , v;
	long long w;
}a[1000010];
int q[20][10010];
int f[100010];
bool cmp(l a , l b){
	return a.w < b.w;
}
int find1(int x){
	if(f[x] == x) return x;
	return f[x] = find1(f[x]);
}
void lj(int x , int y){
	f[x] = y;
}
void tree(){
	bs = 0;
	cnt = 0;
	sort(a+1,a+m1+1,cmp);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m1; i++){
		if(find1(a[i].u) != find1(a[i].v)){
			cnt += a[i].w;
			bs++;
			lj(a[i].u,a[i].v);
		}
		if(bs == n-1) return ;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			cin >> q[i][j];
		}
	}
	m1 = m;
	tree();
	cout << cnt;
	return 0;
}
