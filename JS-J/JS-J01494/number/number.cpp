#include <bits/stdc++.h>
using namespace std;

string s;
int num[15];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(char c : s) num[c-'0']++;
    for(int i=9; i>=0; i--){
        while(num[i]--) cout << i;
    }
    return 0;
}
