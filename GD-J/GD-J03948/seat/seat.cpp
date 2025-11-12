#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[1000] = {};
    for (int i = 0;i < n*m;i++) {
        cin >> a[i];
    }
    if (n == 1 && m == 1){
        cout << "1 1";
    }
    return 0;
}

