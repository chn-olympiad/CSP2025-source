#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a<b;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, c[505];
	long long ans;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) cin >> c[i];
	sort(c+1, c+n+1, cmp);
	int z=0;
	bool h_0=0, h_1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			h_0 = 1;
		}
		else h_1 = 1;
		if(!h_1) z++;
	}
	if(!h_0){
		ans = 1;
		while(n--){
			for(int i=1;i<=n;i++){
				ans *= 2;
				ans %= 998244353;
			}
		}
	}
	else if(m==1){
		int x = 1;
		while(c[x]<z){
			x++;
		}
		ans = n-x+1;
		for(int i=2;i<n;i++){
			ans *= i;
			ans %= 998244353;
		}
	}
	else ans = 0;
	cout << ans;
	return 0;
}
