#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n = 0, maxn = 0;
    for(int i = 1; i <= 100; i++){
        if('1' <= i && i <= '9'){
            n += i;
        }
        maxn = max(n, maxn);
    }
    cout << maxn;
    return 0;
}
