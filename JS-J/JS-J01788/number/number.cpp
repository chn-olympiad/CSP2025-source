#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool isdigit(char c){
    return '0' <= c && c <= '9';
}

int c2i(char c){
    return c - '0';
}

int cnt[15];
string s;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    int l = s.length();
    for (int i=0; i<l; i++){
        if (isdigit(s[i])) cnt[c2i(s[i])]++;
    }

    for (int i=9; i>=0; i--){
        for (int j=1; j<=cnt[i]; j++){
            cout << i;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
