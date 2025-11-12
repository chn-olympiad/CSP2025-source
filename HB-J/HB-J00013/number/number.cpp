#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sl = s.size(),a[1000009] = {},ans = 0,m = 0;
    for(int i = 0;i < sl;i++){
        if(int(s[i]) >= 48 && int(s[i]) <= 57){
            a[m] = s[i] - '0';
            m++;
            ans++;
        }
    }
    sort(a,a + ans,greater<int>());
    for(int i = 0;i < ans;i++){
        cout << a[i];
    }
    return 0;
}
