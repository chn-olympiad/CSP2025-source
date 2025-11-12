#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long p[N] , c[N] , a[N];
long long find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
struct node{
	long long a , b , c;
}g[N];
bool cmp(node x , node y){
	return x.c < y.c;
}
int n , m , k;
long long kk(){
	sort(g + 1 , g + m + 1 , cmp);
	for(int i = 1 ; i <= n ; i ++) p[i] = i;
	long long res = 0 , cnt = 0;
	for(int i = 1 ; i <= m ; i ++){
		long long a = g[i].a , b = g[i].b , c = g[i].c;
		if(find(a) == find(b)) continue;
		p[find(a)] = find(b);
		res += c;
		cnt ++;
		if(cnt == n - 1) break;
	}
	return res;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++){
		long long a , b , c;
		cin >> a >> b >> c;
		g[i] = {a , b , c};
	}
	if(k == 0){
		long long ans = kk();
		cout << ans << '\n';
		return 0;
	}
	for(int i = 1 ; i <= k ; i ++){
		cin >> c[i];
		for(int j = 1 ; j <= n ; j ++){
			cin >> a[j];
			long long u = i , v = j , w = c[i] + a[j] + a[i];
			g[++ m] = {u , v , w};
		}
	}
	long long ans = kk();
	cout << ans << '\n';
	return 0;
}
