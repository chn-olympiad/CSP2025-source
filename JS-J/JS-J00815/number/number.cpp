#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin >> str;
	
	vector<int> vec;
	int count = 0;
	int length = (int)(str.size());
	
	for (int i = 0; i < length; ++i) {
		if ('0' <= str[i] && str[i] <= '9') {
			vec.push_back(str[i] - '0');
			++count;
	    }
	}
	
	sort(vec.begin(), vec.end(), Compare);
	
	for (int i = 0; i < count; i++) {
		cout << vec[i];
	}
	
	return 0;
}
