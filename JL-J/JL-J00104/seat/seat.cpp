#include<bits/stdc++.h>

using namespace std;

int n, m;
int c;
int k = 0;
int a[110];
int b[11][11];
bool d;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    c = a[0];
    sort(a, a + (n * m), cmp);
    for(int i = 1; i <= m; i++) {
        if(i % 2 == 0) {
            for(int j = n; j >= 1; j--) {
                b[j][i] = a[k];
                k++;
            }
        }
        else {
            for(int j = 1; j <= n; j++) {
                b[j][i] = a[k];
                k++;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] == c) {
                cout << j << " " << i <<endl;
                d = true;
                break;
            }
        }
        if(d == true) {
            break;
        }
    }
    return 0;
}
