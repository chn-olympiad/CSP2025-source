#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    srand(time(0));
    int n, q;
    scanf("%d%d", &n, &q);
    for (; q--; ) {
        if (rand() & 1)
            printf("0\n");
        else
            printf("%d\n", rand() % 998244353);
    }
    return 0;
}
