#include<bits/stdc++.h>
using namespace std;
int So[10001];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string ans, s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        So[int(s[i])-'0']++;
    }
    bool flag = 0;
    for(int i = 9 ; i > 0 ; i--){
        if(So[i] != 0){
            flag = 1;
        }
        for(int j = 0 ; j < So[i] ; j++){
            cout << i;
        }
    }
    if(flag == 1){
        for(int i = 0 ; i < So[0] ; i++){
            cout << 0;
        }
    }else{
        cout << 0;
    }
    return 0;
}
