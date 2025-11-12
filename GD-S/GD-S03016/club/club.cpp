#include<bits/stdc++.h>
using namespace std;

int d[10001][3], q[10001];
int t, n, li, cnt, ans;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> n;
		li = n / 2;
		for(int i = 1; i <= n; i++){
			if(d[i][2] == 0 && d[i][3] == 0) cnt++;
			for(int j = 1; j <= 3; j++){
				cin >> d[i][j];
			} 
		}
	} 
	if(cnt == n){
		for(int i = 1; i <= n; i++){
			q[i] = d[i][1];
		}
		sort(q + 1, q + n + 1, cmp);
		for(int i = 1; i <= li; i++){
			ans += q[i];
		}
		cout << ans;
	}
	return 0;
} 
