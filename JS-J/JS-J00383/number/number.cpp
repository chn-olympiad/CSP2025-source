#include <bits/stdc++.h>
using namespace std;
string s;
long long t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (long long i = 0;i <= s.size() - 1;i++){
        t[s[i] - '0']++;
    }
    for (long long i = 9;i >= 0;i--){
        while (t[i]--) cout << i;
    }
    return 0;
}
