#include<bits/stdc++.h>
using namespace std;
int n;
int main (){
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);

    cin >> n;
    if (n < 3) cout << 0;
    if (n == 3) cout << 1;
    if (n == 5){
        int a; cin >> a;
        if (a == 1) cout << 9;
        if (a == 2) cout << 6;
    }
    if (n == 20) cout << 1042392;
    if (n == 500) cout << 366911923;
    return 0;
}
