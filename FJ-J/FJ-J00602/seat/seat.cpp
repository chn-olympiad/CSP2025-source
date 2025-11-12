#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[210], b[15][15];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	int x = a[1];
	for(int i = 2; i <= n*m; i++) cin >> a[i];
	sort(a+1, a+1+n*m, cmp);
	int id1 = 1, idx = 1, idy = 1;
	while(id1 <= n*m && idy <= m){
		if(idy%2 == 1){
			while(idx <= n){
				if(a[id1] == x){
					cout << idy << " " << idx;
					return 0;
				}
				else b[idx++][idy] = a[id1++];
			}
			idy++; idx = n;
		}else{
			while(idx >= 1){
				if(a[id1] == x){
					cout << idy << " " << idx;
					return 0;
				}
				else b[idx--][idy] = a[id1++];
			}
			idy++; idx = 1;
		}
	}
	return 0;
} 
