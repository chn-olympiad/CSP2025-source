#include <bits/stdc++.h>
using namespace std;
//const int maxn = 1e6+9;
string s;
int num[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i]>='0' && s[i] <= '9'){
            num[s[i]-'0']++;
        }
    }
    for(int i = 9;i>=0;i--){
        while(num[i] != 0){
            cout << i;
            num[i]--;
        }
    }
    return 0;
}
