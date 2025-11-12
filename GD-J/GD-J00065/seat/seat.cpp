#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int  a[N], mp[N][N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int eaxm = a[1], idx = 1;
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n; i++){
		if(i % 2 != 0){
			for(int j = 1; j <= m; j++){
				mp[j][i] = a[idx];
				idx++;
			}
		}else{
			for(int j = m; j >= 1; j--){
				mp[j][i] = a[idx];
				idx++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] == eaxm){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
