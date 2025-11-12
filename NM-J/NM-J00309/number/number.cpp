#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cou = 0;
    bool n = false;
    for (int i = 0;i < s.length();i++){
        if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' ||s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0'){
            n = true;
            cou = cou * 10 + s[i];
        }else{
            n = false;
            if (s.length()==1){
                cout << 0;
                return 0;
            }
        }
    }
    cout << cou;
    return 0;
}
