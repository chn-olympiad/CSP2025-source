#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int zero = 0;
bool cmp(int x, int y){
	return (x > y);
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, s2;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if((char)s[i] >= 48 && (char)s[i] <= 57){
			if ((char)s[i] == 48) zero ++;
			a[i] = int(char(s[i])) - 48;
		}
	}
	sort(a, a + s.size(), cmp);
	for(int i = 0; i <= s.size() - zero; i++){
		if (a[i] != 0) cout << a[i];
	} 
	for(int i = 0; i <= zero - 1; i++) cout << 0;
	return 0;
} 
