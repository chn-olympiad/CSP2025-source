#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define N 998244353
using namespace std;
ll n, res;
ll a[5005];
bool vis[5005];
set<string> st;
//check 是看看这些被选中的木棍能不能组成多边形 
bool check(ll x){
	ll sum = 0;
	ll maxn = -1;
	for(int i = 1; i <= n; i ++){
		if(i == x || vis[i]){
			sum += a[i];
			maxn = max(maxn, a[i]);
		}
	}
	if(sum > maxn * 2) return true;
	return false;
}
void dfs(ll x){
	if(x >= 3){
		string s = "0";
		for(int i = 1; i <= n; i ++){
			if(vis[i]){
				s = s + (char)(i);
			}
		}
		st.insert(s);
		if(x > n) return;
	}
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			if(x >= 2) if(!check(i)) continue;
			vis[i] = true;
			dfs(x + 1);
			vis[i] = false;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	memset(vis, false, sizeof vis);
	dfs(0);
	cout << (st.size() + 1) % N;
	return 0;
}