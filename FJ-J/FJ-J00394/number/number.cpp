#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0; i <= l + 2; i++){
		a[i] = -1;
	}
	int z = 0;
	for (int i = 0; i < l; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[++z] = s[i] - 48;
		}
	}
	sort(a + 1, a + z + 1, greater<int>());
	for (int i = 1; i <= z; i++){
		cout << a[i];
	}
	return 0;
}
