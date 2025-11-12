#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
string s;
ll head;
char a[10000010];

bool cmp(char x , char y) {
	return x > y;
}
int main () {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);

	cin >> s;
	for(ll i = 0;i < s.size();i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			head ++;
			a[head] = s[i];
		}
	}

	sort(a + 1 , a + head + 1 , cmp);

	for(ll i = 1;i <= head;i ++) {
		cout << a[i];
	}
	return 0;
}