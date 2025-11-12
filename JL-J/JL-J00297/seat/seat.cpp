#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    vector<int> vc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vc.push_back(arr[i][j]);
        }
    }
    int io = vc[0];
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    int seat[m][n];
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if ((i + 1) % 2 != 0) {
            for (int j = 0; j < n; j++) {
                seat[i][j] = vc[cnt];
                cnt++;
            }

        }
        else {
            for (int k = n - 1; k >= 0; k--) {
                seat[i][k] = vc[cnt];
                cnt++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (seat[i][j] == io) {
                cout << i + 1 << " " << j + 1;
            }
        }
    }
    return 0;
}
