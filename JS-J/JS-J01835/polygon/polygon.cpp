#include<bits/stdc++.h>
using namespace std;

int n, a[5010];
long long ans = 0;

bool s(int x, int y){
	return x > y;
}

void dfs(vector <bool> x, int sum, int maxx){
	if(x.size() == n){
		if(sum > maxx){
			ans++;
		}
		//for(int i = 0;i < n;i++){
		//	cout << x[i];
		//}
		//cout << sum << maxx << endl;
	}
	else{
		x.push_back(0);
		dfs(x, sum, maxx);
		x.pop_back();
		x.push_back(1);
		if(maxx == 0){
			dfs(x, sum, a[x.size()]);
		}
		else{
			dfs(x, sum + a[x.size()], maxx);
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, s);
	if(a[1] == 1){
		ans = 1;
		for(int i = 1;i <= n;i++){
			ans = ans * 2;
			ans = ans % 998244353;
		}
		if(ans < n * n){
			ans += 998244353;
		}
		ans -= n * n;
	}
	else{
		dfs({}, 0, 0);
	}
	cout << ans % 998244353;
	return 0;
}
