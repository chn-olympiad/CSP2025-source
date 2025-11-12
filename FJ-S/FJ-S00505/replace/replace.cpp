#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define MAX_LEN 5000000
string s1, s2, t1, t2, tmp;
int n, q, ls, lt, lt1, nxt[MAX_LEN + 5], ans;
queue <int> que;
stack <int> stk;

string Read() {
	string str = "";
	char ch = getchar();
	while (ch < 'a' || ch > 'z') ch = getchar();
	while (ch >= 'a' && ch <= 'z') {
		str += ch;
		ch = getchar();
	}
	return str;
}
void Write(int x) {
	if (x == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
	while (x) {
		stk.push(x % 10);
		x /= 10;
	}
	while (! stk.empty()) {
		putchar(char('0' + stk.top()));
		stk.pop();
	}
	putchar('\n');
	return;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	s1 = Read();
	s2 = Read();
	for (int i = 2; i <= n; i++) {
		s1 += " " + Read();
		s2 += " " + Read();
	}
//	cout << s1 << endl << s2 << endl;
	ls = s1.length();
	int no, j, fir, lst, tt;
	bool flag;
	while (q--) {
		ans = 0;
		t1 = Read();
		t2 = Read();
		if (t1.length() != t2.length()) {
			Write(0);
			continue;
		}
		lt1 = t1.length();
		fir = lst = -1;
		for (int i = 0; i < lt1; i++) {
			if (t1[i] != t2[i]) {
				lst = i;
				if (fir == -1) fir = i;
			}
		}
//	printf("caocaocaocao");!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (fir == -1 && lst == -1) fir = lst = 0;
		tmp = t1.substr(fir, lst - fir + 1);
		lt = tmp.length();
		nxt[0] = 0;
		no = 0;
		for (int i = 1; i < lt; i++) {
			no = i;
			while (no != 0 && tmp[nxt[no - 1]] != tmp[i]) 
				no = nxt[no - 1];
			if (no == 0) nxt[i] = 0;
			else nxt[i] = nxt[no - 1] + 1;
		}
		j = 0;
		for (int i = 0; i < ls; i++) {
			while (j != 0 && s1[i] != tmp[j]) j = nxt[j - 1];
			if (s1[i] == tmp[j]) j++;
			if (j == lt) {
				que.push(i - j + 1);
				j = nxt[j - 1];
			}
		}
		while (! que.empty()) {
			flag = true;
			j = fir;
			tt = que.front();
//			printf("iii%d\n", tt);
			while (tt >= 0 && s1[tt] != ' ') {
				if (j < 0) {
					flag = false;
					break;
				}
				if (t1[j] != s1[tt] || t2[j] != s2[tt]) {
					flag = false;
					break;
				}
				tt--;
				j--;
			}
			j = fir;
			tt = que.front();
			while (tt < ls && s1[tt] != ' ') {
				if (j >= lt1) {
					flag = false;
					break;
				}
				if (t1[j] != s1[tt] || t2[j] != s2[tt]) {
					flag = false;
					break;
				}
				tt++;
				j++;
			}
			if (flag) {
				ans++;
//				printf("!!!%d\n", que.front());
			}
			que.pop();
		}
		Write(ans);
	}
	return 0;
}

