#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int l = 1;
    string s;
    cin >> s;
    for (int i = 0;i < s.size();i++){
        if ('0' <= s[i] && s[i] <= '9') a[s[i]-'0']++;
        if (s[i] != '0' && '0' < s[i] && s[i] <= '9') l = 0;
    }
    if (l){
        cout << "0";
        return 0;
    }
    string ss = "";
    for (int i = 9;i >= 0;i--){
        for (int j = 1;j <= a[i];j++) ss += char(i+'0');
    }
    cout << ss;
    return 0;
}
