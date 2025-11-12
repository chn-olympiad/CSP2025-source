#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, sc, a[N], s[N][N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> a[i];
	sc = a[1];
	sort(a+1, a+1+n*m, greater<int>());
	int cnt = 1;
	for(int i = 1; i <= m; i += 2){
		for(int j = 1; j <= n; j++){
			s[i][j] = a[cnt++];
		}
		for(int j = n; j >= 1; j--){
			s[i+1][j] = a[cnt++];
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s[i][j] == sc){
				cout << i << " " << j << '\n';
			}
		}
	}
	return 0;
}
