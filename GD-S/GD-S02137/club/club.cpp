#include<bits/stdc++.h> 
using namespace std;
long long t, n, sum, maxn, cnt1, cnt2, cnt3;
struct student{
	long long club1, club2, club3;
}ls[100005];
void dfs(long long k){
	if (k > n){
		maxn = max(sum, maxn);
		return;
	}
	if (cnt1 < n / 2){
		cnt1 ++;
		sum += ls [ k ].club1;
		dfs(k + 1);
		cnt1 --;
		sum -= ls [ k ].club1;
	}
	if (cnt2 < n / 2){
		cnt2 ++;
		sum += ls [ k ].club2;
		dfs(k + 1);
		cnt2 --;
		sum -= ls [ k ].club2;
	}
	if (cnt3 < n / 2){
		cnt3 ++;
		sum += ls [ k ].club3;
		dfs(k + 1);
		cnt3 --;
		sum -= ls [ k ].club3;
	}
}
int main(){
	freopen("club4.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin >> t;
	while (t --){
		sum = maxn = 0;
		cin >> n;
		for (int i = 1;i <= n; ++ i){
			cin >> ls [ i ].club1 >> ls [ i ].club2 >> ls [ i ].club3;
		}
		dfs(1);
		cout << maxn << "\n"; 
	}
	return 0;
}
/*
..+---+
./|  /|
+---+ |
| +-|-+
|/  |/.
+---+.. 
*/
