#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	
	int k = 0;
	int a[100005];
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[k++] = s[i] - '0';
		}
	}
	
	sort(a, a + k);
	
	for (int i = k - 1; i >= 0; --i) {
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 