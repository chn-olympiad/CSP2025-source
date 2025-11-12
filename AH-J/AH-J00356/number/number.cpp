#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],c[15];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    int b = 1;
    for (int i = 0;i < s.size();i++){
        if (s[i] <= '9' and s[i]>= '0') {
            a[b] = s[i]-'0';
            b++;
        }
    }
    b--;
    for (int i = 1;i <= b;i++){
        for (int j = 0;j <= 9;j++){
            if (a[i] == j) c[j]++;
        }
    }
    for (int i = 9;i >= 0;i--){
        for (int j = 1;j <= c[i];j++){
            cout << i;
        }
    }
    return 0;
}
