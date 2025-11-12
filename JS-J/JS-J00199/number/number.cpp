#include <bits/stdc++.h>
using namespace std;
string s;
int num[12];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= '0' and s[i] <= '9'){
            num[ s[i]-'0' ]++;
        }
    }
    int t = 9;
    while(1){
        while(num[t]>0){
            cout << t;
            num[t]--;
        }
        t--;
        if(t < 0)return 0;
    }
    return 0;
}
