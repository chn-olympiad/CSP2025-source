#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
typedef pair <int, int> pll;
int t, n;
int a[N], b[N], c[N];
priority_queue <int> p;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	ll mx = 0, res = 0;
	for(int i = 1; i <= n; i++){
		res += a[i];
		p.push(max(b[i], c[i]) - a[i]);
	}
	for(int i = 1; i <= n / 2; i++){
		res += p.top(), p.pop();
	}
	while(!p.empty()) p.pop();
	mx = max(mx, res);
	res = 0;
	for(int i = 1; i <= n; i++){
		res += b[i];
		p.push(max(a[i], c[i]) - b[i]);
	}
	for(int i = 1; i <= n / 2; i++){
		res += p.top(), p.pop();
	}
	while(!p.empty()) p.pop();
	mx = max(mx, res);
	res = 0;
	for(int i = 1; i <= n; i++){
		res += c[i];
		p.push(max(a[i], b[i]) - c[i]);
	}
	for(int i = 1; i <= n / 2; i++){
		res += p.top(), p.pop();
	}
	while(!p.empty()) p.pop();
	mx = max(mx, res);
	res = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1; i <= n; i++){
		int p = max(a[i], max(b[i], c[i]));
		res += p;
		if(a[i] == p) cnt1++;
		if(b[i] == p) cnt2++;
		if(c[i] == p) cnt3++;
	}
	if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) mx = max(mx, res);
	cout << mx << "\n";
}
int main(){
	//freopen("T.in", "r", stdin);
	//freopen("T.out", "w", stdout);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
