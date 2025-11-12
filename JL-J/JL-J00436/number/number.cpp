#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int num[N], tot;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[i] >= '0' and s[i] <= '9')
            num[++tot] = s[i] - '0';
    sort(num + 1, num + tot + 1, cmp);
    for (int i = 1; i <= tot; i++) printf("%d", num[i]);
    return 0;
}
