#include <bits/stdc++.h>
using namespace std;

int grade[110];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    int grr;
    scanf("%d", &grr);
    grade[1] = grr;
    for (int i = 2; i <= n * m; i++)
        scanf("%d", &grade[i]);
    sort(grade + 1, grade + 1 + n * m, cmp);
    int area;
    for (int i = 1; i <= n * m; i++)
        if (grade[i] == grr) {
            area = i;
            break;
        }
    int lie = area / n;
    if (area % n)
        ++lie;
    int hang = area % n;
    if (hang == 0)
        hang = n;
    if (!(lie % 2))
        hang = n - hang + 1;
    printf("%d %d\n", lie, hang);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
