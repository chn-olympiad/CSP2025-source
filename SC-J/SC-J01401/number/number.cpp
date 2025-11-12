#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 1e6 + 10;
char s[N];
int n, stk[N], tot;
bool cmp (int x, int y) { return x > y; }
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    scanf (" %s ", s + 1);
    n = strlen (s + 1);
    for (int i = 1; i <= n; i++)
        if ('0' <= s[i] && s[i] <= '9')
            stk[++tot] = s[i] - '0';
    std::sort (stk + 1, stk + tot + 1, cmp);
    for (int i = 1; i <= tot; i++) printf ("%d", stk[i]);
    printf ("\n");
    fclose (stdin);
    fclose (stdout);
    return 0;
}