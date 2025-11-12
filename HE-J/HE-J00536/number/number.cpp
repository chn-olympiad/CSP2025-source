#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int a[1000001];

inline bool cmp (int x, int y){
    return x > y;
}

int main(){
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    scanf ("%s", s + 1);
    int n = strlen(s + 1);
    int x = 0;
    for (int i = 1; i <= n; i ++)
        if (s[i] == '0' || s[i] == '1' || s[i] == '2'|| s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
            a[++x] = s[i] - '0';
    sort (a + 1, a + x + 1, cmp);
    for (int i = 1; i <= x; i++)
        printf ("%d", a[i]);
    return 0;
}
//ÃëÀÖ£¨Ï²£© 
