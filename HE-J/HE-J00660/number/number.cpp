#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000020], cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if ((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9')){
			a[i] = s[i];
			cnt++;
		}
	}
	sort(a, a + 1000020);
	for (int i = 1000019; i >= 1000020 - cnt; i--)	printf("%d", a[i] - 48);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
