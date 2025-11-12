#include<bits/stdc++.h>
using namespace std;

char s[1000001];
int a[1000001];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    int num = 0, l = strlen(s + 1);
    for (int i = 1; i <= l; i++) {
        if (s[i] < 60)
            a[++num] = s[i] - 48;

    }
    sort(a + 1, a + num + 1);
    for (int i = num; i >= 1; i--)
        printf("%d", a[i]);
    return 0;
}
