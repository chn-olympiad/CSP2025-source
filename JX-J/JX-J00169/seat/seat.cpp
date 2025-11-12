#include <bits/stdc++.h>
using namespace std;
int n, m, x , y, c, r;
int a[256];
int main(){
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);    
    int n;
    cin >> n >> m;
    for (int  i = 1; i <= n * m; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n * m; ++i){
        if(a[i] > a[1]){
            x += 1;
        }
    }
    y = x + 1;
    if (y % n == 0){
        c = y / n;
    }else{
        c = y / n + 1;
    }
    if (c % 2 == 0){
        if (y % n == 0){
            r = 1;
        }else{
            r = n - (y % n) + 1;
        }
    }else{
         if (y % n == 0){
            r = n;
        }else{
            r = y % n;
        }       
    }
    cout << c << ' ' << r;
    return 0;
}