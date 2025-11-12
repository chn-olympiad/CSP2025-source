#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    char b[s.length()]={0};
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57){
            b[i] = s[i];
        }
    }


    char r;

    for(int i = 0;i<s.length();i++){
        for(int j = i;j<s.length();j++){
        while(b[i]<b[j]){
                r=b[i];
                b[i] = b[j];
                b[j] = r;
            }
        }
    }

    cout << b;

    return 0;
}
