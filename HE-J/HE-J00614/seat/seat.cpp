#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	int o[105];
	for(int i = 0; i < n*m; i++){
		cin >> o[i];
	}
	for(int i = 0; i <= n*m; i++){
		if(o[0] < o[i]){
			cnt++;
		}
	}
	if(cnt >m && (cnt /m)%2 == 1){
		cout << cnt/m + 1  << " " << cnt%m + 1;
	}else if(cnt> m && (cnt/m)%2 == 0){
		cout << cnt / m +1 << " " << m - cnt % m;
	}else{
		cout << 1 << " " << cnt;
	}
	return 0;
} 
