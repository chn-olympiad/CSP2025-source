#include <iostream>
#include <string>
#include <algorithm>
std::string t;
int a[1000001];
int cnt;

int main() {
	freopen("number.in","r" , stdin);
	freopen("number.out","w" , stdout);
	std::cin >> t;
	for (int i = 0; i < t.length(); ++i) {
		if (t[i] == '0' || t[i] == '1' || t[i] == '2' || t[i] == '3' || t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || t[i] == '8' || t[i] == '9') {
			a[cnt] = t[i] - '0';
			++cnt;
		}
	}
	sort(a, a + cnt, std::greater<int>());
	for (int i = 0; i < cnt; ++i)
		std::cout << a[i];
	return 0;
}
