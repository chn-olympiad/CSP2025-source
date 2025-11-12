#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool isnum(char c) {
	return c >= '0' && c <= '9';
}

bool cmp(int a, int b) {
	return a > b;
}

string s;
char a[1000005];
int cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (isnum(s[i])) {
			a[++cnt] = s[i];
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//...../\........../\.....
//..../..\......../..\....
//.../....\....../....\...
//../......\..../......\..
//./........\../........\.
///..........\/..........\
//\....................../
//.\.........WLT......../.
//..\................../..
//...\................/...
//....\............../....
//.....\............/.....
//......\........../......
//.......\......../.......
//........\....../........
//.........\..../.........
//..........\../..........
//...........\/...........

