#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int>number;
	for (int i = 0; i < s.size(); ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			int t = s[i] - '0';
			number.emplace_back(t); 
		}
	}
	sort(number.begin(),number.end());
	for (int i = number.size() - 1; i >= 0; --i) {
		cout << number[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}