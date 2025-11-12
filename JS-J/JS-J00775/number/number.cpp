#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int vh[20], ans = 0;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	memset(vh, 0, sizeof(vh));
	for (int i = 0; i < (int)(s.size()); i++){
		if (s[i] >= '0' && s[i] <= '9'){
			vh[s[i] - '0']++;
		}
	}
	//cout << vh[5] << endl;
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= vh[i]; j++){
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
