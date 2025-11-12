#include <bits/stdc++.h>
using namespace std;
int a[10], n, i;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	while(s[i] != '\0'){
		n++;
		i++;
	};
	for(int i = 0; i < n; i++) if('0' <= s[i] && s[i] <= '9') a[s[i] - '0']++;
	for(int i = 9; i >= 0; i--) for(int j = 0; j < a[i]; j++) cout << i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}