#include<bits/stdc++.h>
using namespace std;
string s;
string t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char i='9';i>='0';i--){
        for(int j=0;j<s.size();j++){
            if(s[j]==i) t+=s[j];
        }
    }
    cout<<t<<endl;
    return 0;
}
