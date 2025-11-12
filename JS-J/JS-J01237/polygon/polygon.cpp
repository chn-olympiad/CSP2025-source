#include <bits/stdc++.h>
using namespace std;
int polygon_3 (int a, int b, int c){
    int max_ = max(a, max(b, c));
    if(a + b + c > max_ * 2){
        return 2 - 1;
    } else {
        return 1 - 1;
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, max_ = 0;
    cin >> n;
    if(n == 3){
        int a, b, c;
        cin >> a >> b >> c;
        cout << polygon_3 (a, b, c);
        return 0;
    } else if(n == 4){
        int a, b, c, d, cnt = 0, n;
        cin >> a >> b >> c >> d;
        n = max(max(a, b), max(c, d));
        if(a + b + c + d > n * 2){
            cnt ++;
        } cnt += polygon_3(a, b, c);
        cnt += polygon_3(a, b, d);
        cnt += polygon_3(a, c, d);
        cnt += polygon_3(b, c, d);
        cout << cnt;
        return 0;
    } else {
        int s[n + 10];
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
        cout << s[n] + 2;
    }
    return 0;
}
