#include <bits/stdc++.h>
using namespace std;
string s;
int record[10];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(char c: s)
        if(c >= '0' && c <= '9') ++record[c - '0'];
    for(int i = 9; i >= 0; --i)
        while(record[i]--) cout << i;
    return 0;
}
