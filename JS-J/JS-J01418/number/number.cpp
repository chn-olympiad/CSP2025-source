#include <bits/stdc++.h>
using namespace std;
string s;
string t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i = 0; i < s.size() ; i++){
        if(isdigit(s[i]))
            t+=s[i];
    }
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(t[0]-'0'==0)
        cout<<0;
    else
        cout<<t;
    return 0;
}
