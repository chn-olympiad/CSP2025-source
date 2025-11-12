#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string s;
    cin>>s;
    string b="";
    bool n;
    for (int i=0;i<s.length();i++){
        if (s[i]>='0' && s[i]<='9'){
            b+=s[i];
        }
    }
    for (int i=0;i<b.length();i++){
        n=true;
        for (int j=i+1;j<b.length();j++){
            if (b[i]<b[j]){
                swap (b[i],b[j]);
                n=false;
            }
        }
        if (n==true){
            break;
        }
    }
    cout<<b;
    return 0;
}
