#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)

const int N = 150;
int n, m, k, a[N];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    k = n * m;
    rep(i, 1, k)
        scanf("%d", &a[i]);
    int R = a[1], v = 0, xx = 0, yy = 0;
    sort(a + 1, a + k + 1);
    reverse(a + 1, a + k + 1);
    rep(i, 1, m) {
        if(i % 2 == 1) {
            rep(j, 1, n) {
                int x = (i - 1) * n + j;
                if(a[x] == R)
                    xx = i, yy = j;
            }
        } else {
            per(j, n, 1) {
                int x = i * n - j + 1;
                if(a[x] == R)
                    xx = i, yy = j;
            }
        }
    }
    printf("%d %d\n", xx, yy);
}
