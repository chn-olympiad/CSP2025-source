#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[10000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        if(isdigit(s[i])) a[cnt++] = s[i] - '0';
    }
    sort(a,a+cnt,greater<int>());
    for(int i = 0 ; i < cnt ; i++) cout << a[i];
    return 0;
}
