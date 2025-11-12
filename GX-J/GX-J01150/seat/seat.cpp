#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Node{
    int x, y;
    int cj;
    int num;
}a[120], s[120][120];

bool cmp (Node a, Node b) {
    return a.cj > b.cj;
}

int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].cj;
        a[i].num = i;
    }

    sort (a + 1, a + n * m + 1, cmp);

    int x = 1;
    for (int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (a[x].num == 1) {
                    s[i][j] = a[x];
                    cout << j << " " << i;
                    x++;
                    return 0;
                }
                else {
                    s[i][j] = a[x];
                    x++;
                }
            }
        }

        else {
            for (int i = n; i >= 1; i--) {
                if (a[x].num == 1) {
                    s[i][j] = a[x];
                    cout << j << " " << i;
                    x++;
                    return 0;
                }
                else {
                    s[i][j] = a[x];
                    x++;
                }
            }
        }
    }



    /*
    cout << endl << endl;
    for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m ;j++){
                cout << s[i][j].cj << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=n*m;i++)cout<<a[i].cj<<" ";
    cout << endl << endl << x;
    */

    return 0;
}
