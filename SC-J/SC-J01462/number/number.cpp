#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s;
vector<int> num;
bool cmp(const int a, const int b) {
	return a >= b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i = 0; i < s.length();i++) {
		if(s[i] >= '0'&& s[i] <= '9') num.push_back(s[i]-'0');
	}
	sort(num.begin(), num.end(), cmp);
	if(num[0] == 0) cout << 0; 
	else {
		for(int i = 0; i < num.size();i++) {
			cout << num[i];
		}
	}
	return 0;
}