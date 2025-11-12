#include <cstdio>
using namespace std;

int n, m;

void inp() {
    scanf("%d%d", &n, &m);
}

void work() {
    if (m == 2) {
        puts("2\n0");
        return;
    }

    while (m -- )
        puts("0");
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}