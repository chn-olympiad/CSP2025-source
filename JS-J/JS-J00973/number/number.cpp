#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int cnt[10];

int main(){

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> str;
    for (char c: str){
        if ('0' <= c && c <= '9'){
            cnt[c-'0']++;
        }
    }
    for (int i=9; i>=0; i--){
        for(int j=0; j<cnt[i]; j++){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}