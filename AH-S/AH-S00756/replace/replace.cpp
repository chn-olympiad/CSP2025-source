#include <bits/stdc++.h>

#define N 400010

using namespace std;

int n, q;
string s1[N], s2[N];
int siz[N];
int b1[N], b2[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline void solve(string str1, string str2) {
    int x1, x2;
    int sizz = str1.size();
    str1 = " " + str1;
    str2 = " " + str2;
    for(int i = 1; i <= sizz; ++i) {
        if(str1[i] == 'b') {
            x1 = i;
            break;
        }
    }
    for(int i = 1; i <= sizz; ++i) {
        if(str2[i] == 'b') {
            x2 = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(x1 - x2 == b1[i] - b2[i] && x1 >= b1[i] && x2 >= b2[i] && sizz - x1 >= siz[i] - b1[i] && sizz - x2 >= siz[i] - b2[i]) {
            ++cnt;
        }
    }
    writeln(cnt);
    return;
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

    n = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		siz[i] = s1[i].size();
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
	}

    for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= siz[i]; ++j) {
			if(s1[i][j] == 'b') {
				b1[i] = j;
			}
			if(s2[i][j] == 'b') {
				b2[i] = j;
			}
		}
	}
	while(q--) {
		string str1, str2;
		cin >> str1 >> str2;
		solve(str1, str2);
	}

    return 0;
}
