#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, id;
} a[100];
bool cmp(node c, node b) {return (c.x > b.x);}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        int x;
        cin >> x;
        a[i].x = x;
        a[i].id = i;
    }
   sort (a + 1, a + n * m + 1, cmp);
    int x = 1;
    int flag = 1;
    int cur = 1;
    while (cur <= n * m) {
        //cout << x << ' ' << ceil(1.0 * cur / n) << endl;
        if (a[cur].id == 1) {
           cout << ceil(1.0 * cur / n) << ' ' << max(1, min(x, n)) << endl;
           return 0;
        }
        if (flag == 1) {
            x++;
            if (x == n) {
                flag = 0;
                x++;
            }
        } else {
            x--;
            if (x == 1) {
                flag = 1;
                x--;
            }
        }
        cur++;
    }
    return 0;
}
