#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main (){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			cnt++;
		}
	}
	int a[cnt+1];
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			a[i] = s[i] - 48;
		}
	}
	sort (a, a+cnt+1);
	int b[cnt];
	for (int i = 1; i <= cnt; i++){
		b[i] = a[i];
		cout << b[i] << " " << a[i] << endl;
	}
	for (int i = cnt; i >= 1; i--){
		cout << b[i];
	}
	return 0;
}
