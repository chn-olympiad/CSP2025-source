#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt, b[1000005];
int cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    for (int i = 0; i < 1000003; i++){
        if (a[i] >= '0' && a[i] <= '9'){
            b[++cnt] = a[i] - '0';
        }
    }
    sort(b + 1, b + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++){
        cout << b[i];
    }
    return 0;
}













