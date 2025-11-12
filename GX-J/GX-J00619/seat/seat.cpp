#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105][105];
int x[15];

int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    if (x[1] = 100) {
        cout << a[1][1];
    }
    else if(x[1] = 99)
        cout << a[1][2];
        else if (x[1] = 98)
            cout << a[2][2];
            else if (x[1] = 97)
                cout << a[2][1];
                else if (x[1] = 96)
                    cout << a[3][1];
                    else if (x[1] = 95)
                        cout << a[3][2];
                        else if (x[1] = 94)
                            cout << a[3][3];
                            else if (x[1] = 93)
                                cout << a[4][1];
                                else if (x[1] = 92)
                                    cout << a[4][2];
                                    else if (x[1] = 91)
                                        cout << a[4][3];
                                        else if (x[1] = 90)
                                            cout << a[4][4];
    return 0;
}
