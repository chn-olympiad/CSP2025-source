#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c;
ll a[15];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    while(cin >> c){
        if(c >= '0' && c <= '9'){
            a[c - '0']++;
        }
    }
    for(ll i = 9; i >= 0; i--){
        while(a[i]--){
            cout << i;
        }
    }
    return 0;
}
