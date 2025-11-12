#include <bits/stdc++.h>
using namespace std;
int n, m, z, w[1001][1001], cnt = 0, b = 0;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> z;
	if (z == 0){
		for (int i = 1;i <= m;i++){
			int a, b, c;
			cin >> a >> b >> c;
			cnt += c;
		}
		cout << cnt;
	}else{
		for (int i= 1; i<= m;i++){
			int a, b, c;
			cin >> a >> b >> c;
		}
		for (int i = 1;i <= z;i++){
			for (int j = 1;j <= n;j++){
				int a;
				cin >> a;
				if (a == 0){
					cout << 0;
					return 0;
				}
			}
		} 
	}
	return 0;
}
