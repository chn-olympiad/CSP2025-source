#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s;
vector<int> num;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (isdigit(s[i]))
			num.push_back(s[i] - '0'); 
	}
	sort(num.begin(), num.end(), greater<int>());
	if (num[0] == 0) puts("0");
	else {
		for (int i = 0; i < (int)num.size(); i++) 
			printf("%d", num[i]);
		putchar('\n');
	}
	return 0;
}
