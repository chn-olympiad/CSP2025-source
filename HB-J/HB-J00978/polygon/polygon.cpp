#include<bits/stdc++.h>
using namespace std;
int a[101];
bool m(vector<int> s){
	int maxn = -1 , sum = 0;
	for (auto i : s){
		maxn = max(maxn , i);
		sum += i;
	}
	return 2 * maxn < sum;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n , ans = 0;
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=(1 << n) - 1; i++){
		vector<int> t;
		for (int j = 0; j<=30; j++){
			if((i >> j) & 1) t.push_back(a[j + 1]);
		}
		if (t.size() >= 3){
			if (m(t)) ans ++;
		}
	}
	cout << ans;
	return 0;
}
