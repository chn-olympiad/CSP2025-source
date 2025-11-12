#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int x;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
			a[x] = s[i] - '0';
			x++;
		}
	}
	sort(a, a + x, greater<int>());
	for(int i = 0; i < x; i++){
		cout << a[i];
	}
	return 0;
}
