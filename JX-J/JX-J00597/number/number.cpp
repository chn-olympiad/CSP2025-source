#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int num[N];
int change (int x, int y) {
    return x > y;
}
int main() {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    scanf ("%s", s);
    int len = strlen (s);
    int tot = 0;
    for (int i = 0; i < len; i ++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num[tot ++] = s[i] - '0'; 
        }
    }
    sort (num, num + tot, change);
    for (int i = 0; i < tot; i ++) {
        printf ("%d", num[i]);
    }
    return 0;
}