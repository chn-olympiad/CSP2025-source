#include <bits/stdc++.h>
using namespace std;
int n, m, s[505], c[505], a[505];
const int MOD = 998244353; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		char ch;
		cin >> ch;
		s[i] = ch - '0';
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		a[i] = i;
	}
	long long res = 0;
	do{
		int cnt = 0, ans = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == 0){
				cnt++;
				continue;
			}
			if(cnt >= c[a[i]]){
				cnt++;
				continue;
			}
			ans++;	
		}
		if(ans >= m) res++;
		if(res >= MOD) res -= MOD;
	}while(next_permutation(a + 1,a + 1 + n));
	cout << res;
	return 0;
} 
