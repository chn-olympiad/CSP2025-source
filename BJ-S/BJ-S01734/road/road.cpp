#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e9 + 9;

int n, m, k;
int cost[MAX_N][MAX_N] = {0};
//long long vc[MAX_N][MAX_N] = {0}; // village cost

int r; //lu
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> cost[i][j];
        }
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= n; i++) {
            cin >> cost[j + m][i];
        }
    }

    int temp[MAX_N][MAX_N] = {0};

    //bubble sort
    int o = ((1 + (m - 1)) * (m - 1))/ 2;
    for (int i = 1; i <= o; i++) {
        if (cost[i][3] > cost[i + 1][3]) {
            for (int j = 1; j <= 3; j++) {
                temp[i][j] = cost[i + 1][j];
                cost[i + 1][j] = cost[i][j];
                cost[i][j] = temp[i][j];
            }
        }
        for (int j = 1; j <= 3; j++) {
            cout << cost[i][j];
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

