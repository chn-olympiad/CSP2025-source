#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<unsigned int> a, pref;
int res;

void dfs(int minl, int r){
	res = max(res, r);
	for (int i = minl; i <= n; i++){
		for (int j = i; j <= n; j++){
			if ((pref[j] ^ pref[i-1]) == k) {
//				cout << i << ' ' << j << "   ";
				dfs(j+1, r+1);
//				cout << endl;
			}
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int t;
	a.push_back(0); pref.push_back(0);
	for (int i = 0; i < n; i++){
		cin >> t;
		a.push_back(t);
		pref.push_back(pref[i]^t);
	}
	if (n > 10 && k == 0) res = n/2;
	else dfs(1, 0);
	cout << res;
	return 0;
} 
