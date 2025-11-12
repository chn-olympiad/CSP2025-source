#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin  >>  n  >>  m;
    for(int i = 0;i < n * m;++i){
        cin  >>  a[i];
    }
    r = a[0];
    sort(a, a + n * m);
    for(int i = n * m;i >= 0;--i){
        if(a[i] == r){
            r = n * m - i - 1;
            break;
        }
    }
    cout  <<  r / n + 1  <<  " ";
    if((r / n) % 2 == 0){
        cout  <<  (r % n) + 1;
    }else{
        cout  <<  n - (r % n);
    }
    return 0;
}
