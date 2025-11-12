#include <bits/stdc++.h>
using namespace std;
int mp[15][15];
int fenshu[105];
bool cmp(int diyi, int dier){
	return diyi > dier;
}
int xiaor;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> fenshu[i];
	}
	xiaor = fenshu[1];
	sort(fenshu + 1, fenshu + n * m + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				mp[j][i] = fenshu[++cnt];
			}
		}
		else{
			for(int j = n; j >= 1; j--){
				mp[j][i] = fenshu[++cnt];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] == xiaor){
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
} 
