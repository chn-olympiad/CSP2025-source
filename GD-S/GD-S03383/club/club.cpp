#include<iostream>
#include<algorithm>
#define int long long
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
using namespace std;
int n, t, x[100005], y[100005], z[100005], ans, k[100005];
bool cmp(int a, int b){
	return a > b;
}
bool checkB(){
	rf(1, i, n) if(y[i] || z[i]) return false;
	return true;
}
void solveB(){
	sort(x + 1, x + n + 1, cmp);
	rf(1, i, n / 2) ans += x[i];
	cout << ans << "\n";
}
void dfs1(int cur){
	if(cur == n + 1){
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans2 = 0;
		rf(1, i, n){
			if(k[i] == 0) cnt1++;
			else if(k[i] == 1) cnt2++;
			else cnt3++;
		}
		if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
		rf(1, i, n){
			if(k[i] == 0) ans2 += x[i];
			else if(k[i] == 1) ans2 += y[i];
			else ans2 += z[i];
		}
		ans = max(ans, ans2);
		return;
	}
	k[cur + 1] = 0;
	dfs1(cur + 1);
	k[cur + 1] = 1;
	dfs1(cur + 1);
	k[cur + 1] = 2;
	dfs1(cur + 1);
	//k[cur + 1] = 0;
}
void solve2(){
	dfs1(0);
	cout << ans << "\n";
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = -1;
		cin >> n;
		rf(1, i, n) cin >> x[i] >> y[i] >> z[i];
		if(checkB()) solveB();
		else solve2();
		rf(1, i, n) x[i] = y[i] = z[i] = 0;
	}
	return 0;
}

