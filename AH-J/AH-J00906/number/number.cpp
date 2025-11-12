#include "bits/stdc++.h"
#define int long long
using namespace std;
string s;
bool cmp(char x,char y){
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    string tmp="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')tmp+=s[i];
    }
    sort(tmp.begin(),tmp.end(),cmp);
    int k=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]=='0'){
            tmp.erase(i,1);
            if(i>0)i--;
            else i=0;
        }else break;
    }
    if(tmp=="")tmp="0";
    cout<<tmp;
    return 0;
}

