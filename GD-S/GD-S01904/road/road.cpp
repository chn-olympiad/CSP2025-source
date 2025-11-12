#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxm = 1000005;
const int maxn = 10025;
struct S{
	int l, r;
	long long w;
}a[maxm], b[maxn * 10];
int f[maxn], c[maxn];
long long w[15][maxn], ans;
int n, m, k, cnt = 0;
bool cmp(S a, S b){
	return a.w < b.w;
}
int fi(int x){
	if(f[x] == x) return x;
	return f[x] = fi(f[x]);
}
void join(int x, int y){
	x = fi(x), y = fi(y);
	f[x] = y;
}
long long g(int x){
	long long sum = 0;
	for(int i = 0;i < k;i++){
		if((1 << i) & x) sum += c[i];
	}
	return sum;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> a[i].l >> a[i].r >> a[i].w;
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= m;i++){
		if(fi(a[i].l) != fi(a[i].r)){
			join(a[i].l, a[i].r);
			ans += a[i].w;
			cnt++;
			a[cnt] = a[i];
		}
	}
	for(int i = 0;i < k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++) cin >> w[i][j];
	}
	for(int i = 1;i < (1 << k);i++){
		long long sum = g(i);
		if(sum > ans) continue;
		for(int j = 1;j <= n + k;j++) f[j] = j;
		int kk = 0;
		for(int j = 0;j < k;j++){
			if((1 << j) & i){
				for(int k = 1;k <= n;k++){
					kk++;
					b[kk].l = j + 1 + n, b[kk].r = k, b[kk].w = w[j][k];
				}
			}
		}
		sort(b + 1, b + 1 + kk, cmp);
		for(int j = 1, jj = 1;j <= cnt || jj <= kk;){
			if((j <= cnt && a[j].w < b[jj].w) || jj > kk){
				if(fi(a[j].l) != fi(a[j].r)){
					join(a[j].l, a[j].r);
					sum += a[j].w;
				}
				j++;
			}else{
				if(fi(b[jj].l) != fi(b[jj].r)){
					join(b[jj].l, b[jj].r);
					sum += b[jj].w;
				}
				jj++;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}