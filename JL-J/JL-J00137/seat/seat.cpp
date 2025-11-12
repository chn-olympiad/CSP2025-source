#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r", stdin);
    freopen("seat.out","w", stdout);
    int n, m;
    cin >> n >> m;
    int seat = 0, grade, g;
    for(int i=0; i<n*m; i++){
        cin >> g;
        if( i == 0 ){
            grade = g;
        }else{
            if( g > grade ) seat ++;
        }
    }
    int c, y;
    if( seat % (2*n) >= n ){
        c = 2 * (seat/ (2 * n)) + 2;
        y = 2 * n - seat % (2 * n);
    }else if( seat % (2*n) < n ){
        c = 2 * (seat / (2 * n)) + 1;
        y = seat % (2 * n) + 1;
    }
    cout << c <<" "<< y;
    return 0;
}
