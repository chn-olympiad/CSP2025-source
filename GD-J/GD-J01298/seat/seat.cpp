#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, m;
int a[N][N];
int x;
int s[N*N];
bool cmp(int l, int r){
	return l > r;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> s[i];
	x = s[1];
	sort(s+1, s+n*m+1, cmp);
	int t = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1) for(int j = 1; j <= m; j++) t++, a[i][j] = s[t];
		else for(int j = m; j >= 1; j--) t++, a[i][j] = s[t];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == x){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
