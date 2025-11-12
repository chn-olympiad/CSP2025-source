#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1001];
int l = 1, r = 1;
int t;

bool cnt(const int &x, const int &y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i]);
    }
    t = a[1];
    sort(a + 1, a + 1 + n * m, cnt);
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == t) {
            break;
        }
        if(r & 1) {
            if(l == n) {
                r++;
            }
            else {
                l++;
            }
        }
        else {
            if(l == 1) {
                r++;
            }
            else {
                l--;
            }
        }
        if(a[i] == t) {
            break;
        }
    }
    printf("%d %d", r, l);
}
