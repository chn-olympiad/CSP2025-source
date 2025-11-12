#include <bits/stdc++.h>
using namespace std;
string n[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            n[s[i]-'0']+=s[i];
        }
    }
    cout<<n[9]<<n[8]<<n[7]<<n[6]<<n[5]<<n[4]<<n[3]<<n[2]<<n[1]<<n[0];
    return 0;
}
