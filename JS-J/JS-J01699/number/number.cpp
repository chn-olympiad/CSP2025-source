#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char tmp;
ll a[10] = {0};
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    while(cin >> tmp){
        if(tmp <= '9' && tmp >= '0'){
            a[tmp - '0']++;
        }
    }for(ll i = 9; i >= 0; i--){
        for(ll j = 1; j <= a[i]; j++) cout << i;
    }cout << endl;
    return 0;
}
