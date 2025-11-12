#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001];
string s;
int cnt = 0, l = 0;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >>m;
	cin >> s;
	if (m == n){
		for (int i = 0;i < s.size();i++){
			if (s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		for (int i = 1;i <= n;i++){
			cin >> a[i];
			if (a[i] == 0){
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}else{
		cout << 1;
	}
}
