#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const int MAXNUM = 15;

int n;
int num[MAXNUM];
char s[MAXN];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) 
		if (s[i] >= '0' && s[i] <= '9') ++num[ s[i] - 48 ];
	for (int i = 9; i >= 0; --i) {
		char t = i + '0';
		for (int j = 1; j <= num[i]; ++j)
		printf("%c", t);
	}
	cout << endl;
	
	return 0;
}
