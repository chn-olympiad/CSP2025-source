#include<bits/stdc++.h>
using namespace std;
string s;
string ans = "";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 1; i <= s.length(); i++){
        if(s[i] == '1'||s[i] == '2'||s[i] == '3'||s[i] == '4'||s[i] == '5'||s[i] == '6'||s[i] == '7'||s[i] == '8'||s[i] == '9'){
            ans += s[i];
        }
    }if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"){
        ans = s;
    }
    cout << ans <<endl;

}
