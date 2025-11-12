#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const long long P = 998244353, N = 510;
long long n, m, s[N], c[N], ans = 1, cnt;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 1){
			cnt++;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if (cnt == 0){
		cout << 0 << endl;
	}
	else{
		sort(c+1, c+n+1);
		for(int i = 1; i <= n; i++){
			if(c[i] == 0){
				if (i != n){
					ans = (ans + P)% P * (n-i) % P;
				}
			}
			else{
				ans = (ans + P)% P * (n-i+1) % P;
			}
		}
		ans = ans % P;
		cout << ans % P << endl;
	}
	return 0;
}
