#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int pos = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[++pos] = int(s[i] - '0');
		}
	}
	sort(a + 1, a + pos + 1, cmp);
	for (int i = 1; i <= pos; i++){
		cout << a[i];
	}
	return 0;
}
