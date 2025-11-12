#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 998244353;
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[N];
int ans = 0;
bool st[N];
vector<int> v;

bool check(){
	if(v.size() < 3) return false;
	int sum = 0, mx = 0;
	for(auto j : v){
		mx = max(mx, j);
		sum += j;
	}
	return (sum > 2 * mx);
}

void dfs(int u){
	if(u > n){
		if(check()) ans ++;
		ans %= mod;
		return ;
	}
	
	if(st[u]) return;
	st[u] = true;
	v.push_back(a[u]);
	dfs(u + 1);
	v.pop_back();
	st[u] = false;
	dfs(u + 1);
	
}

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
}
