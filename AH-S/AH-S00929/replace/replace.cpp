#include <bits/stdc++.h>

using namespace std;

int read() {
    int x = 0, k = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') k = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * k;
}

char c1[5000005], c2[5000005];
int a[200005], b[200005];
char t1[5000005], t2[5000005];
int xe[200005], ye[200005];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n = read(), T = read(), jb = 1;
    for (int i = 1; i <= n; i++) {
		if (i == 1) a[1] = 1, b[1] = 0;
		if (i > 1) a[i] = b[i - 1] + 1, b[i] = b[i - 1];
		char c = getchar();
		while (c < 'a' || c > 'z') c = getchar();
		while (c >= 'a' && c <= 'z') {
			if (c != 'a' && c != 'b') jb = 0;
			++b[i]; c1[b[i]] = c; c = getchar();
		}
		//printf("<1 %d %d>", a[i], b[i]);
		for (int j = a[i]; j <= b[i]; j++) {
			c = getchar(); if (c >= 'a' && c <= 'z') c2[j] = c;
		}
			
		//	printf("<2 %d %d>", a[i], b[i]);
	}
	
	if (jb == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= b[i]; j++) {
				if (c1[j] == 'b') xe[i] = j - a[i] + 1;
				if (c2[j] == 'b') ye[i] = j - a[i] + 1;
			//	printf("%d %d\n", xe[i], ye[i]);
			}
		}
		while (T--) {
			scanf("%s %s", t1 + 1, t2 + 1);
			int s = 0, len = strlen(t1 + 1);
			int X = 0, Y = 0;
			
			for (int j = 1; j <= len; j++) {
				if (t1[j] == 'b') X = j;
				if (t2[j] == 'b') Y = j;
			}
			for (int i = 1; i <= n; i++) {
				int x = xe[i], y = ye[i];
				if (X - Y == x - y && X >= x && Y >= y && len - X >= b[i] - a[i] + 1 - x && len - Y >= b[i] - a[i] + 1 - y)
					s++;
			}
			printf("%d\n", s);
		}
	}
    return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 1
aaab baaa
baa aba
baa aab
aaaab abaaa
*/
