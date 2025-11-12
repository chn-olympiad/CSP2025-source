#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<int> a(n*m);


    for (int i=0; i < n*m; ++i){
        cin >> a[i];
    }

    int r = a[0];
    sort(a.begin(), a.end());

    /*
    for (int i=0; i < n*m; ++i){ //debug 1
        cout << a[i] << ' ';
    }
    */

    // I want to know r is number.
    double r_number;
    for (int i=0; i < n*m; ++i){
        if (a[i] == r){
            r_number = n*m-i;
        }
    }

    // cout << r_number; // debug 2

    int l = ceil(r_number / n); // line
    cout << l << ' ';
    if (l % 2 == 1){ // start -> end
        cout << r_number - (l-1)*n;
    }else{ // end -> start
        cout <<  m + 1 - r_number - (l-1)*n;
    }

    return 0;
}
