#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool rev(int a, int b) {return a > b;}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	int num[1000005];
	
	cin >> s;
	
	int cnt = 0;
	
	for(unsigned int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			num[cnt++] = s[i] - 48;
		}
	}
	
	sort(num, num + cnt, rev);
	
	for(int i = 0; i < cnt; i++) printf("%d", num[i]);
	
	return 0;
}
