#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[10];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    char c;
    while(cin >> c){
        if('0' <= c && c <= '9'){
            int x = c - '0';
            cnt[x]++;
        }
    }
    bool f = 0;
    for(int i = 9;i >= 1;i--){
        while(cnt[i]--){
            cout << i;
            f = 1;
        }
    }
    if(!f){
        cout << "0\n";
        return 0;
    }
    while(cnt[0]--){
        cout << 0;
    }
    cout << '\n';
    return 0;
}