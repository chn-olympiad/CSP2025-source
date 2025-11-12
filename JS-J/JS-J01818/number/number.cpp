#include <bits/stdc++.h>
using namespace std;
string a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']+=s[i];
        }
    }
    for(int i=9;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
//LG uid 1210103
//I am Elaina's dog qwq.
//IOI AK ME
