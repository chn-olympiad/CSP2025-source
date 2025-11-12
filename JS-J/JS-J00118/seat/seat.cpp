#include<bits/stdc++.h>
using namespace std;
const int N = 11;
int a[N][N], n, m;
int num[N * N];
bool cmp(int x, int y) {
    return x > y;
}
int r, tot = 1;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++) {
        cin >> num[i];
    }
    r = num[1];
    sort(num + 1, num + 1 + n * m, cmp);
    for(int i = 1;i <= n;i ++) {
        if(i % 2 == 1) {
            for(int j = 1;j <= m;j ++) {
                if(num[tot] == r) {
                    cout << i << ' ' << j;
                    return 0;
                }
                tot ++;
            }
        }else {
            for(int j = m;j >= 1;j --) {
                if(num[tot] == r) {
                    cout << i << ' ' << j;
                    return 0;
                }
                tot ++;
            }
        }

    }
    return 0;
}
