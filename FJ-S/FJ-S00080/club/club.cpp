#include<bits/stdc++.h>
using namespace std;
long long ans = -1;
const int N = 100005;
long long a[N][5], h[5];
int vis[N][5];
int t, n ;
//long long tmax[N], tmin[N];
void f(int x){
	if(x == n + 1){
		if(h[1] > n / 2 || h[2] > n / 2 ||h[3] > n / 2 ) return;
		long long sum = 0;
		for(int i = 1; i <= n ;i++){
			for(int j = 1; j <= 3; j++){
				if(vis[i][j] == 1){
					sum += a[i][j];
				}
			}
		}
		
		ans = max(ans, sum);
		return ;
	}
	for(int k = 1; k <= 3; k++){
		vis[x][k] = 1;
		h[k]++;
		f(x + 1);
		h[k]--;
		vis[x][k] = 0;
	}
	
}


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t ;
	while(t--){
		cin >> n;
		for(int i = 1 ;i <= n ;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			
		}
		f(1);
		for(int i = 1; i <= n ;i++){
			for(int j = 1; j <= 3; j++){
				vis[i][j] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	
	
	return 0;
}
