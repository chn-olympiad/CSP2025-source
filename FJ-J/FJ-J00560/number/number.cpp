#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

int tong[15];
char ch;
//priority_queue <char> que;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (true) {
		ch = getchar();
		if (! ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))) 
			break;
		if (ch >= 'a' && ch <= 'z') continue;
		tong[ch - '0']++;
	}
	for (int i = 9; i >= 0; i--) 
		for (int j = 1; j <= tong[i]; j++) 
			putchar(char(i + '0'));
//	while (true) {
//		ch = getchar();
//		if (! ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))) 
//			break;
//		if (ch >= 'a' && ch <= 'z') continue;
//		que.push(ch);
//	}
//	while (! que.empty()) {
//		putchar(que.top());
//		que.pop();
//	}
	return 0;
}

