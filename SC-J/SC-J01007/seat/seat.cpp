#include <cstdio>
#include <algorithm>

const int N = 109;

int n, m, s, num = 0;

int a[N];

std::pair<int, int> p[N];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);

    s = a[1];
    
    std::sort(a + 1, a + 1 + n * m, [](int x, int y) {
        return x > y;
    });

    int i = 1, j = 1;
    while (true) {
        p[a[++num]] = std::make_pair(i, j);
        if (j % 2 == 0) {
            if (i != 1)
                i--;
            else {
                if (j == m)
                    break;
                j++;
            }
        }
        else {
            if (i != n) 
                i++;
            else {
                if (j == m)
                    break;
                j++;
            }
        }
    }

    printf("%d %d", p[s].second, p[s].first);

    fclose(stdin);
    fclose(stdout);

    return 0;
}