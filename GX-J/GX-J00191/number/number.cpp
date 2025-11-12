#include <bits/stdc++.h>
using namespace std;
int main(){

    string s,w;
    cin >> s;
    for(int i = 1;i<=s.length();i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]==7||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            cout << s[i];
        }

    }



    return 0;
}
