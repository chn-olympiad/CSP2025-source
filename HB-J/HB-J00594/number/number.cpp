#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size(),nc[MAX],cou = 0;
    for(int i = 0;i < n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            nc[cou++] = s[i] - '0';
        }
    }
    sort(nc,nc + cou);
    for(int i = cou - 1;i >= 0;i--){
        cout << nc[i];
    }
    return 0;
}
