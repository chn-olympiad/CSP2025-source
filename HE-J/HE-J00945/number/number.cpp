#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int len = s.size();
	vector<int> num; //´æ´¢ËùÓĞÊı×Ö 
	for (int i = 0; i < len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			num.push_back(s[i] - '0');
	
	sort(num.begin(), num.end(), cmp);
	
	if (num[0] == 0) {
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < num.size(); i++)
		cout << v[i];
	
	return 0;
}
