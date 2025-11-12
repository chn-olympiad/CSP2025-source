#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string n;
	cin >> n;
	
	int len;
	vector<int> num;
	len = n.size();
	for(int i = 0; i < len; i++) {
		if(n[i] >= '0' && n[i] <= '9') {
			num.push_back(int(n[i] - '0'));
		}
	}
	
	sort(num.begin(), num.end(), cmp);
	
	len = num.size();
	for(int i = 0; i < len; i++) {
		cout << num[i];
	}
	return 0;
}
