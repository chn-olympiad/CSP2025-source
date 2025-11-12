#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n = s.length();
    for(int i = 0; i <= n-1; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        for(int j = 1; j <= cnt[i]; j++){
            cout << i;
        }
    }
    return 0;
}
