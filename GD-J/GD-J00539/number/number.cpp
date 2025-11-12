#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	vector<int> vec;
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			vec.push_back(c - '0');
		}
	}
	sort(vec.begin(), vec.end(), greater<int>());
	for (const int &i : vec) {
		printf("%d", i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
