#include <bits/stdc++.h>

using namespace std;

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    int row,col,c[110],h,x=1,y=1;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> row >> col;
    for (int i=0;i<row*col;i++) {
        cin >> c[i];
    }
    h = c[0];
    sort(c,c+row*col,cmp);
    for (int i=0;i<row*col;i++) {
        if (c[i]==h) {
            break;
        }
        if (i/row%2) {
            y--;
        }
        else {
            y++;
        }
        if (y<1) {
            y++;
            x++;
        }
        if (y>row) {
            y--;
            x++;
        }
    }
    cout << x << " " << y;
    return 0;
}
