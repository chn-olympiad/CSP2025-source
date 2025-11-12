#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    int a[15] = {};
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i <= s.size()-1 ; i++){
        if('0' <= s[i] && s[i] <= '9'){
            a[s[i]-'0']++;
        }
    }
    int flag = 1;
    for(int i = 9;i >= 1 ; i--){
        if(a[i] > 0){
            flag = 0;
        }
    }
    if(flag == 1){
        cout << "0";
        return 0;
    }
    for(int i = 9;i >= 0 ; i--){
        for(int j = 1;j <= a[i] ; j++){
            cout << i;
        }
    }
    return 0;
}
