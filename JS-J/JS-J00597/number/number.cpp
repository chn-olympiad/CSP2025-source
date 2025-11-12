#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+5;
int nu = 0,num[N];
int ans = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ll = s.length();
    cin >> s;
    for (int i = 0;i < s.length();i++){
        if (s[i] >= '0' && s[i]<='9'){
            num[++nu] = s[i]-'0';
        }
    }
    sort(num+1,num+nu+1);
    for (int i = nu;i >= 1;i--){
        cout << num[i];
    }
    return 0;
}
