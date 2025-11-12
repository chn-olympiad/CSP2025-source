#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int sum = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < int(s.size()); i++){
		if(isdigit(s[i])){
			sum++;
			a[sum] = s[i] - '0';
		}
	}
	sort(a + 1, a + sum + 1);
	for (int i = sum; i >= 1; i--) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
