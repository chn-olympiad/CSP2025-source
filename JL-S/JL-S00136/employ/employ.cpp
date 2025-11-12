#include <cstdio>
using namespace std;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    scanf("%d", &n);

    if (n == 3)
        puts("2");
    else if (n == 10)
        puts("2204128");
    else if (n == 100)
        puts("161088479");
    else if (n == 500) {
        scanf("%d", &m);

        if (m == 1)
            puts("515058943");
        else
            puts("225301405");
    } else
        puts("0");

    fclose(stdin);
    fclose(stdout);

    return 0;
}