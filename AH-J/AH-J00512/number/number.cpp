#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int f[100];
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    for(int i=0; i<str.size(); i++){
        char c = str[i];
        if('0' <= c && c <= '9'){
            f[c - '0'] ++;
        }
    }
    for(int i=9; i>=0; i--){
        if(f[i] == 0) continue;
        for(int j=1; j<=f[i]; j++){
            cout<<i;
        }
    }
    return 0;
}
