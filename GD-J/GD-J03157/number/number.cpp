#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){	
    string s;
	int num[15];
	int l, n;
	cin >> s;
	l = s.size();
	n = 0;
	for (int i = 0; i < l; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			n += 1;
			a[n] = int(s[i]) - 48;
		}
	}
	for (int i = 0; i <= 9; i++) {
		num[i] = 0;
	}
	int m = 0;
	for (int i = 1;i <= n;i++){
		num[a[i]] = num[a[i]] + 1;
	}
	for (int i = 9; i >= 0; i--){
		while(num[i] > 0){
			cout << i;
			num[i]--;
		}
	}
	return 0;
}
