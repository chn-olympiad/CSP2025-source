#include<bits/stdc++.h>
using namespace std;

const int L = 1e7;
char s[L];
int num[L], p = 0;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    (void)freopen("number.in", "r", stdin);
    (void)freopen("number.out", "w", stdout);
    (void)scanf("%s", s);
    for(int i = 0; s[i] != 0; i++) {
        if(0 <= s[i] - '0' && s[i] - '0' <= 9) {
            num[p++] = (s[i] - '0');
        }
    }
    sort(num, num + p, comp);
    for(int i = 0; i < p; i++) {
        (void)printf("%d", num[i]);
    }
    return 0;
}

