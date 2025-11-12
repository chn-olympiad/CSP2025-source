#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    const int MX = 1e6+10;
    int a[MX],nm = 0;
    string s;
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){a[nm] = s[i]-'0';nm++;}
    }
    sort(a,a+nm);
    for(int i = nm-1;i >= 0;i--){
        cout << a[i];
    }
    return 0;
}
