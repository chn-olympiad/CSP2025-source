#include <iostream>

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    unsigned int m, n, k;
    std::cin >> m >> n >> k;
    int u[m], v[m], w[m], c[k], a[k][n];
    for (int i = 0; i < m; i++)
    {
        std::cin >> u[m] >> v[m] >> w[m];
    }
    for (int i = 0; i < k; i++)
    {
        std::cin >> c[i];
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    fclose(stdout);
    fclose(stdin);
    return 0;
}