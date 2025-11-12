#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int num[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	char c;
	int cnt = 1;
	
	while (cin >> c) {
		if (c >= '0' && c <= '9') {
			num[cnt++] = c - '0';
		}
	}
	
	sort(num + 1, num + cnt, greater<int>());
	
	for (int i = 1; i < cnt; i++) {
		cout << num[i];
	}
	
	return 0;
}

