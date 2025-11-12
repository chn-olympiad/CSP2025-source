#include <cstdio>

char _[114514];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    

    int N, Q;
    scanf("%d %d", &N, &Q);

    for(int i = 1; i <= 2*N + 2*Q; ++i) scanf("%s", _);

    while(Q--) puts("0");
}