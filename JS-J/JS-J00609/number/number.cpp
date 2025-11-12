#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
char s[N];
int c[N];
int len = 0;

int main () {
    //printf("use : %.10f\n", (sizeof(n) + sizeof(c) + sizeof(s) + sizeof(len)) / 1024. / 1024.);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            c[++len] = s[i] - '0';
    }
    sort(c + 1, c + len + 1);
    for (int i = len; i >= 1; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}
