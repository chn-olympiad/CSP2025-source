#include<bits/stdc++.h>
using namespace std;

char a[1000010];
int l;
int b[1000001], r;

bool cnt(const int &x, const int &y) {
    return x > y;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", a + 1);
    l = strlen(a + 1);
    for(int i = 1; i <= l; i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            b[++r] = a[i] - '0';
        }
    }
    sort(b + 1, b + 1 + r, cnt);
    for(int i = 1; i <= r; i++) {
        printf("%d", b[i]);
    }
    return 0;
}
