#include <bits/stdc++.h>
using namespace std;
string s;
int l[10];
bool cmp(int a,int b){
    return a >= b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0;i < s.size();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            l[s[i] - '0']++;
        }
    }
    for (int i = 9;i >= 0;i--){
        if (l[i] != 0) for (int j = 1;j <= l[i];j++) cout << i;
    }
    return 0;
}
