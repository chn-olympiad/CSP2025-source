#include "bits/stdc++.h"
using namespace std;

const int N = 1e6 + 10;
char s[N];
int a[50];

inline int read() {
    int fa = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fa = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * fa;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int i = 1; i <= l; i ++) {
        if (s[i] >= '0' && s[i] <= '9')
            a[s[i] - '0'] ++;
    }
    for (int i = 9; i >= 0; i --)
        for (int j = 1; j <= a[i]; j ++)
            printf("%d", i);
}
