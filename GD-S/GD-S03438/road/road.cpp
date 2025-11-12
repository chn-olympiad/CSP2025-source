#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+7, M = 1e6+7, K = 11, inf = 1e18+7;
int n, m, k;
int q;
int a[K][N];
struct uct{
	int x, y, z;
	bool operator <(const uct v)const{ return z < v.z;}
}b[M], c[N];
struct yew{
	int f[N+K];
	void clear(){
		for(int i = 1; i <= n+k; i++) f[i] = i;
	}
	int find(int x){
		if(f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	bool merge(int x, int y){
		x = find(x), y = find(y);
		if(x != y){
			f[x] = y;
			return true;
		}
		return false;
	}
}e;
int getans(){
	sort(b+1, b+q+1);
	e.clear();
	int i = 1, j = 1, sum = 0;
	while(i < n || j <= q){
		if((i < n) && (j > q || c[i].z < b[j].z)){
			if(e.merge(c[i].x, c[i].y)) sum += c[i].z;
//			cout << "co" << c[i].x << ' ' << c[i].y << ' ' << c[i].z << '\n';
			i++;
		}else{
			if(e.merge(b[j].x, b[j].y)) sum += b[j].z;
//			cout << "ch" << b[j].x << ' ' << b[j].y << ' ' << b[j].z << '\n';
			j++;
		}
	}
	return sum;
}
signed main(){
	//is long long?
	//The N is enough?
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y >> b[i].z;
	for(int i = 1; i <= k; i++) for(int j = 0; j <= n; j++) cin >> a[i][j];
	int ans = 0, sum = 0;
	sort(b+1, b+m+1);
	e.clear();
	for(int i = 1; i <= m; i++){
		if(e.merge(b[i].x, b[i].y)){
			ans += b[i].z;
			c[++q] = b[i];
		}
	}
	for(int le = 1; le < (1<<k); le++){
		q = 0;
		sum = 0;
		for(int i = 1; i <= k; i++){
			if((le&(1<<(i-1))) == 0) continue;
//			cout << i << ' ';
			sum += a[i][0];
			for(int j = 1; j <= n; j++) b[++q] = (uct){n+i, j, a[i][j]};
		}
		ans = min(ans, getans()+sum);
//		cout << ' ' << ans << '\n';
	}
	cout << ans;
	return 0;
} 
