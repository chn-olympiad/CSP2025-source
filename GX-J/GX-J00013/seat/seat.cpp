#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m, c = 1, r = 0, arr[105] = {}, R;
    bool front = true;
    cin >> n >> m;
    for(int i = 0; i < n*m; i++) {
        cin >> arr[i];
    }
    R = arr[0];
    sort(arr, arr+n*m, [](int a, int b){return a > b;});
    for(int i = 0; ; i++) {
        if(front) {
            r++;
            if(r > m) {
                c++; r=m;
                front = !front;
            }
        }
        else {
            r--;
            if(r < 1) {
                r=1; c++;
                front = !front;
            }
        }
        if(arr[i] == R) break;
    }
    cout << c << ' ' << r << '\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
