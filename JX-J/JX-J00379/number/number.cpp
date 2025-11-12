#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    long long b[1000005];
    cin >> a;
    for (int i = 0; i < a.length(); i++){
        b[i] = -1;
    }
    for (int i = 0; i < a.length(); i++){
        if (a[i] >= 48 and a[i] <= 57) b[i] = a[i] - 48;
    }
    sort (b, b + a.length());
    for (int i = a.length() - 1; i > 0; i--){
        if (b[i] == -1) break;
        cout << b[i];
    }
    return 0;
}
