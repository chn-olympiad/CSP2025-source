#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int p[5010] , n , cnt;
int fd(int y , int s , int sum){
	for(int i = s ; i <= n ; i++){
		if(y >= 2 && sum > p[i]) cnt++ , cnt %= mod;
		fd(y + 1 , i + 1 , sum + p[i]);
	}
}

signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n; int tmp = 0;
	for(int i = 1 ; i <= n ; i++) cin >> p[i] , tmp += p[i];
	if(tmp == n){
		for(int i = 3 ; i <= n ; i++){
			int t = 1;
			for(int j = n ; j >= n - i + 1 ; j--)
				t = (t * j) % mod;
			cnt = (cnt + t) % mod;
		}cout << cnt;
		return 0;
	}sort(p + 1 , p + n + 1);
	fd(0 , 1 , 0);
	cout << cnt;
	return 0;
}

