#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int n, t;
int club[3] = {0};
int a[MAX_N][3];

int main() {
    freopen("club.in","r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;

    int sum;
    int ans; //under
    int d[3] = {};

    while (t--) {
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {

            sum += max(a[i][1], a[i][2]);
            sum += max(sum, a[i][3]);
            //if (a[i][2] >= a[i][1] && )
        }
        cout << sum << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}