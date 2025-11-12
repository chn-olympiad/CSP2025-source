#include <bits/stdc++.h>
using namespace std;

int n, a[50005];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;

    if (n <= 2){
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << 0;
        return 0;
    }
    else if(n == 3){
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y > z && x + z > y && y + z > x)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
