#include <bits/stdc++.h>

using namespace std;

int n, a[10010];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    if(n == 3){
        if(max({a[0], a[1], a[2]}) >= (a[0] + a[1] + a[2] - max({a[0], a[1], a[2]}))){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }
    cout << n - 3 + 1 << endl;

    return 0;
}