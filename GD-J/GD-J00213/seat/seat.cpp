#include <bits/stdc++.h>
using namespace std;
const int N = 15, M = 15;
int n, m;
int a[N*M];
int b[N][M] = {0};
int cmp(int a, int b){
	return a > b;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int s = a[1];
	int cnt = 1;
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1;i <= n;i++){
		int k = m;
		for(int j = 1;j <= m;j++){
			int ans = a[cnt++];
			if(j%2 == 0){
				b[k--][i] = ans;
			}
			else{
				b[j][i] = ans;
			}
		}
	}
	int d = 1;
	for(int i = 1;i <= n;i++){
		for(int j=1;j <= m;j++){
			if(s == b[j][i]) cout << i << " " << j;
		}
		d++;
	}
	return 0;
}
