#include <iostream>
#include <algorithm>
using namespace std;

const int MXN = 1e6 + 5;
char s[MXN];
int p, num[MXN];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s;
	for (int i = 0; s[i]; i += 1){
		if ('0' <= s[i] && s[i] <= '9') num[++p] = s[i] - '0';
	}
	
	sort(num + 1, num + p + 1, [](const int& a, const int& b){
		return a > b;
	});
	if (num[1] == 0) cout << "0";
	else for (int i = 1; i <= p; i += 1) cout << num[i];
	return 0;
}

