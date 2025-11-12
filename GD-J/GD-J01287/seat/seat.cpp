#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[105];

int main() {
    freopen("seat.in", "r",stdin);
    freopen("seat.out", "w", stdout);
    cin >> N >> M;
    for(int i=1; i<=N * M; i++) {
        cin >> arr[i];
    }
    int sc = arr[1];
    sort(arr + 1, arr + 1 + N * M, greater<int>());
    int idx = 0;
    for(int i=1; i<=N * M; i++) {
        if (arr[i] == sc) {
            idx = i;
            break;
        }
    }
    int r = 1, c = 1;
    for(int i=2; i<=idx; i++) {
        if (c & 1) {
            if (r == N) {
                c++;
            } else {
                r++;
            }
        } else {
            if (r == 1) {
                c++;
            } else {
                r--;
            }
        }
    }
    cout << c << ' ' << r;

    return 0;
}