#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int a[15];

void init(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
}

void solve(){
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            a[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        for(int j = 1; j <= a[i]; j++){
            cout << i;
        }
    }
}

void close(){
    fclose(stdin);
    fclose(stdout);
}

int main(){
    init();
    solve();
    close();
}
