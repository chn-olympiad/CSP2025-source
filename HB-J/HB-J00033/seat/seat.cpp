#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000], s[1000][1000];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int nm = n * m;
    for (int i = 1; i <= nm; i++)
        cin >> a[i];
    int xr = a[1], x;
    sort(a + 1, a + nm + 1, cmp);
    /*for (int i = 1; i <= nm; i++)
        cout << a[i] << " ";*/
    for (int i = 1; i <= nm; i++){
        if(a[i] == xr){
            x = i;
            break;
        }
    }
    //cout << x << endl;
    int rm = 0, rn = 0, y = 0;
    int h = x / n;
    if (x % n == 0){
        rm = x / n;
        if (rm % 2 == 0)
        /*for (int i = h + 1; i <= x; i++)
                y++;*/
            rn = 1;
        else
            rn = n;
    }
    else{
        rm = h + 1;
        if (rm % 2 == 0){
            for (int i = (h * n + 1); i <= x; i++){
                if (i == x)
                    break;
                y++;
            }
            rn = n - y;
        }
        else{
            for (int i = (h * n + 1); i <= x; i++){
                if (i == x)
                    break;
                y++;
            }
            rn = 1 + y;
        }
    }
    //cout << y << endl;
    cout << rm << " " << rn;
    return 0;
}
