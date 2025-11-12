#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll n, a[5010];
ll ans;
void bfs(ll f, ll sum, ll idx){
	for(int i = idx + 1; i <= n; i++){
		if(f >= 3){
			if(sum > a[i]) {
				ans++;
				ans %= MOD;
			}
		}
		bfs(f + 1, sum + a[i], i);
	}
}
bool cmp(int x, int y){
	return x < y;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	bfs(1, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

