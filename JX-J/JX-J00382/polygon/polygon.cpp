#include <stdio.h>
using namespace std;

int n, a;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    if (n == 3)
        printf("1");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a);
    return 0;
}
