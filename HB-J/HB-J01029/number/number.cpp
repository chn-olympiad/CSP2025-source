#include <bits/stdc++.h>
using namespace std;
string s;
map<char,int> m;
string ans;
string realans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9') m[s[i]]++;
    }
    for(int i = 9; i >= 0; i--){
        if(m['0'+i] == 0) continue;
        for(int j = 1; j <= m['0'+i]; j++)  cout << i;
    }
    return 0;
}
//QWQ 100pts

/*
a ma ti la si (chao jue qi pao yin
*/
