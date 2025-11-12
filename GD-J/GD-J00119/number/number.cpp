#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e6;

int num[N + 5];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int tot = 0;
	string s;
	cin >> s;
	
	for (int i = 0;i < (int)(s.size());i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num[++tot] = s[i] - '0';
		}
	}
	
	sort(num + 1,num + tot + 1);
	
	if (num[tot] == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = tot;i >= 1;i--) {
		cout << num[i];
	}
	cout << endl;
	
	return 0;
}
