//t3 xor
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
#define pos(x) (x < 0 ? 1 : x)
using namespace std;
long long n, k, a[500005], cnts1[5];
struct t{
	int l, r;
	t(int a, int b){l = a, r = b;}
};
vector<t> w;
bool check1(){
	rf(1, i, n) if(a[i] > 1) return false;
	return (k <= 1);
}
void solve1(){
	rf(1, i, n) cnts1[a[i]]++;
	cout << cnts1[k];
}
bool check2(){
	rf(1, i, n) if(a[i] > 255) return false;
	if(k > 255) return false;
	return true;
}
bool cmp(t a, t b){
	return (a.l == b.l ? a.r < b.r : a.l < b.l);
}
void solve2(){
	long long now, dp[500005];
	memset(dp, 0, sizeof dp);
	rf(1, i, n) if(a[i] == k) w.emplace_back(i, i); 
	rf(1, i, n){
		now = a[i];
		rf(i + 1, j, n){
			now ^= a[j];
			if(now == k) w.emplace_back(i, j);
		}
	}
	sort(w.begin(), w.end(), cmp);
	rf(1, i, w.size()){
		rf(1, j, n){
			if(w[i - 1].r <= j) dp[j] = max(dp[pos(w[i - 1].l - 1)] + 1, dp[j]);
		}
	}
	cout << dp[n];
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	rf(1, i, n) cin >> a[i];
	if(check1()) solve1();
	else if(check2()) solve2();
	else cout << 1;
	return 0;
}

