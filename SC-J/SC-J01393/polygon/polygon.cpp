# include <bits/stdc++.h>
# define int long long
# define endl '\n'
using namespace std;

int a[5010], ans = 0, n;
bool useful[5010];

vector <int> v;

const int mod = 998244353;

bool check(){
	if(v.size() < 3) return false;
	int summ = 0, maxx = -1;
	for(int i=0;i<v.size();i++){
		summ += v[i];
		maxx = max(maxx, v[i]);
	}
	return summ > maxx*2;
}

void dfs(int f){
	for(int i=f;i<n;i++){
		if(v.size() && a[i] < v[v.size()-1]) continue;
		if(!useful[i]) continue;
		v.push_back(a[i]);
		useful[i] = false;
		if(check()) ans ++;
		ans %= mod;
//		for(int j=0;j<v.size();j++) cout << v[j] << " ";
//		cout << endl;
		dfs(f + 1);
		useful[i] = true;
		v.pop_back();
	}
}

signed main(){
//	ios::asnc_with_stdio(false);
//	cout.tie(0);
//	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for(int i=0;i<5000;i++) useful[i] = true;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a, a+n);
//	for(int i=0;i<n;i++) cout << a[i] << " ";
//	cout << endl;
	dfs(0);
	cout << ans % mod;
	return 0;
}
