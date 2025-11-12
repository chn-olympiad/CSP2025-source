#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const int M = 5e3 + 5;
int n, k, tl[N], tr[N], pos;
ll xors[N], a[N], dp[M * M];

struct Node{
	int l, r;
}A[M * M];

struct node{
	int l, r;
	bool operator < (const node &a) const {
		return l < a.l;
	}
};
set<node> vis;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i], xors[i] = (xors[i - 1] ^ a[i]);
	if(n <= 10000){
		for(int l = 1; l <= n; ++l){
			for(int r = l; r <= n; ++r){
				if((xors[r] ^ xors[l - 1]) == k) A[++pos] = (Node){l, r};
			}
		}
		for(int i = 1; i <= pos; ++i){
			dp[i] = 1;
			for(int j = 1; j < i; ++j){
				if(A[j].r < A[i].l) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ll ans = 0;
		for(int i = 1; i <= pos; ++i) ans = max(ans, dp[i]);
		cout << ans << "\n";
		return 0;
	}
	vis.insert((node){0, 0});
	vis.insert((node){n + 1, n + 1});
	for(int len = 1; len <= n; ++len){
		for(auto it = vis.begin(); it != vis.end(); ){
			int L = (*it).r + 1;
			if(L > n) break;
			int R = (*(++it)).l - 1;
			if(R > n) break;
			for(int l = L; l <= R; ){
				int r = l + len - 1;
				if(r > R) break;
				if((xors[r] ^ xors[l - 1]) == k){
					tl[++pos] = l, tr[pos] = r;
//					cout << "a:" << a[l] << ' ' << a[r] << "\n";
					l = r + 1;
				}
				else ++l;
			}
		}
		for(int i = 1; i <= pos; ++i) vis.insert((node){tl[i], tr[i]}), tl[i] = tr[i] = 0;
		pos = 0;
	}
	cout << vis.size() - 2 << "\n";
//	for(auto it = vis.begin(); it != vis.end(); ++it) cout << (*it).l << ' ' << (*it).r << "\n";
	return 0;
}
// CCF doesn't let this problem of me become true, so I f**k CCF s**t.
