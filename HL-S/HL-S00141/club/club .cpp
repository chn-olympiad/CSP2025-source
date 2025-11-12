#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int tong, n;
long long q[N][5];
long long ans[N];
long long cnt;

void dfs(int k, int a[]){
	if(k == n + 1){
		//cout << ans[n] << endl;
		return ;
	}
	for(int i = 1; i <= 3; i++){
		a[i]++;
		//cout << k <<" "<< i <<" " << a[i]<< endl;
		if(a[i] <= n / 2){
			ans[k] = ans[k-1] + q[k][i];
			if(k == n){
				cnt = max(cnt, ans[n]);
			}	
			//cout << k <<" "<< i <<" " << a[i]<< " " <<ans[k] << endl;
			dfs(k + 1, a);
			a[i]--;
			ans[k] -= q[k][i]; 
		}
		else{
			a[i]--;
			continue;
		}
	}
}

int main(){
	freopen("club.in ", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> tong;
	for(int i = 1; i <= tong; i++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> q[i][1] >> q[i][2] >> q[i][3];
		}
		for(int i = 1; i <= N; i++){
			ans[i] = 0;
		}
		int tong[4] = {};
		tong[1] = 0;
		tong[2] = 0;
		tong[3] = 0;
		dfs(1, tong);
		cout << cnt << endl;
	}
	return 0;
} 
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
