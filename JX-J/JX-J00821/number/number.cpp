#include <bits/stdc++.h>
using namespace std;
const int x = 10e+3;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[x]={};
    cin >> s;
    int n = s.size();
    for (int i = 0;i < s.size();i++){
        if ((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z')){
            continue;
        }
        else{
            a[i] = s[i]-'0';
        }

    }
    //for (int i = 0;i < s.size();i++) a[i] = s2[i] - '0';
    sort(a,a+n);
    for (int i = s.size()-1;i >= 0;i--){
        if (a[i] < 0){
            return 0;
        }
        else{
            cout << a[i];
        }

    }
    return 0;
}
