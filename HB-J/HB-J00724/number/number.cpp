#include <bits/stdc++.h>
using namespace std;
string s;
char num[1000005];
int pos=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i]>='0' && s<='9'){
            num[pos]=s[i];
            pos++;
        }
    }
    sort(num,num+pos);
    for (int i = num.length(); i >= 0; i--){
        cout << num[i];
    }
    return 0;
}
