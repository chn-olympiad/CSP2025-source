#include <bits/stdc++.h>
using namespace std;
int bk[15];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i <= s.size();i++){
        if(s[i] <= '9' && s[i] >= '0'){
            bk[s[i] - '0'] ++;
        }
    }
    for(int i = 9; i >= 0;i--){
        if(bk[i] != 0){
            for(int j = 1;j <= bk[i];j++){
                cout << i;
            }
        }
    }
    return 0;
}
