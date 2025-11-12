#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x, int y){
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++) cin >> a[i];
    int x = a[1];
    sort(a+1, a+n*m+1, cmp);
    int num;
    for(int i = 1;i <= n*m;i++){
        if(a[i] == x){
            num = i;
            break;
        }
    }
    //cout << num << endl;
    int grp = num/(2*n);
    int yu = num%(2*n);
    //cout << grp << " " << yu << endl;
    if(yu == 0){
        cout << grp*2 << " " << n;
    }else{
        if(yu > n){
            cout << grp*2+2 << " " << n+1-(yu%n);
        }else{
            cout << grp*2+1 << " " << yu;
        }
    }
    return 0;
}
