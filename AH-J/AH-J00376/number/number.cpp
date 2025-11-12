#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t+=s[i];
        }
    }
    sort(t.begin(),t.end());
    for(int i=t.size()-1;i>0;i--){
        cout<<t[i];
    }
    return 0;
}
