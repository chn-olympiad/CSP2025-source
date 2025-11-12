#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
	cin >> s;
	int len = s.size();
	for (int i=0; i<len; i++){
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int x : v) {
		printf("%d", x);
	}
    return 0;
}
