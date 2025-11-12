#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if (n<3) cout << 0;
    else if (n==3){
        int a,b,c;
        cin >> a >> b >> c;
        int ms=max(max(a,b),c);
        if (a+b+c>2*ms) cout << 1;
        else cout << 0;
    }
    else cout << n-2;
    return 0;
    }
