#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int n, m, ans, c[505], d[505];
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i]; d[i] = i;
	}
	do{
//		for(int i = 1; i <= n; i++) cout << c[i] << ' ';
//		cout << endl;
		int cnt = 0, a = 0;
		for(int i = 0; i < n; i++){
//			cout << cnt << ' ' << (cnt >= c[i]) << (s[i] == '0') << endl;
			if(cnt >= c[d[i+1]]){
				cnt++;
				continue;
			}
			if(s[i] == '0'){
				cnt++;
				continue; 
			}
			cnt = 0;
			a++;
		}
//		cout << a << endl;
		if(a >= m) ans = (ans + 1) % mod; 
	}while(next_permutation(d+1, d+1+n));
	cout << ans;
	return 0;
}
