#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m, p[501] = {};
	long long cnt = 1;
	string a;
	cin >> n >> m; 
	cin >> a;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	int len = a.length();
	sort(p, p+n);
	if(m == 1){
		int ans = 0, peo = 0;
		for(int i = 0; i < len; i++){
			if(a[i] == '1'){
				ans = i;
				break;
			}
		}		
		for(int j = 0; j < n; j++){
			if(p[j] > ans){
				peo++;
			}
		}
		for(int i = 2; i <= n - ans; i++){
			cnt *= i;
			if(cnt > 998244353){
				cnt %= 998244353;
			}
		}	
		cout << len << " " << ans << " " << peo << " "; 
		cout << (cnt + (ans * (n - peo))) % 998244353 << endl;
		return 0;
		
	}else if(n == m){
		for(int i = 2; i <= n; i++){
			cnt *= i;
			if(cnt > 998244353){
				cnt %= 998244353;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
} 
