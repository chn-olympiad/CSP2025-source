#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+5;

char str[N];
int l;
int num[10];

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	l = strlen(str);
	for(int i = 0;i < l;++i) {
		if('0' <= str[i] && str[i] <= '9') num[str[i]-'0']++;
		else continue;
	}
	
	for(int i = 9;i >= 0;--i) {
		while(num[i] > 0) {
			cout << char(i+'0');
			--num[i];
		}
	}
	return 0;
} 