#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010], cnt;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++cnt] = s[i] - 48;
		}
	}
	sort(a + 1, a + cnt + 1);
	if(cnt > 1 && !a[cnt]){
		cout << 0 << endl;
		return 0;
	}
	for(int i = cnt; i >= 1; i--){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
