#include<bits/stdc++.h>
using namespace std;
#define cfalse cin.tie(0)->sync_with_stdio(0)
#define int long long
const int inf = 998244353;
const int maxn = 1e5 + 5;
int n, m;
int ans = 0;
int arr[maxn];
string s;
bool vis[maxn];
struct node{
	int x;
	int id;
};
void dfs(int p, int num, int id){
	if(p == n - 1){
		int res = 0;
		if(p - num < arr[id] && s[p] == '1')res++;
		if(num + res >= m)ans++;
		ans %= inf;
		return;
	}else{
		int res = 0;
		if(p - num < arr[id] && s[p] == '1')res++;
		for(int i = 0; i < n; i++){
			if(vis[i])continue;
			vis[i] = 1;
			dfs(p + 1, num + res, i);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cfalse;
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	for(int i = 0; i < n; i++){
		vis[i] = 1;
		dfs(0, 0, i);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}
