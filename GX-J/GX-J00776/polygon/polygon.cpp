#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r" ,stdin);
    freopen("polygon.out","w" ,stdout);
    int n,st[5009] = {0};
    cin>>n;
    for(itn i = 0; i < n; i++){
        cin>>st[i];
    }
    cout << n % 998244353;
    return 0;
}
