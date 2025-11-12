#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 5e3+10;
int ans = 0, n, a[N];

unordered_map<string, bool> mp;

bool check(string& cas, int sum, int Max){
	return cas.size() >= 3 && sum > Max*2;
}

void dfs(string& cas, int sum, int Max, int pos){
	
	if(pos > n) return;//越界
	
	cas += (pos + ' '); 
	
	if(check(cas, sum+a[pos], max(Max, a[pos])) && !mp[cas]){
		++ans;
		mp[cas] = true;
	}
	
	dfs(cas, sum+a[pos], max(Max, a[pos]), pos+1);
	
	cas.erase(cas.size()-1, 1);
	
	if(check(cas, sum, Max) && !mp[cas]){
		++ans;
		mp[cas] = true;
	}
	
	dfs(cas, sum, Max, pos+1);
} 

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	string cas;
	dfs(cas, 0, 0, 1);
	cout << ans << endl;
	
	return 0;
}