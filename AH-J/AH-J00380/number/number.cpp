#include <bits/stdc++.h>
using namespace std;
string s;
string a;
bool cmp(const char &x,const char &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z') continue;
        a+=s[i];
    }
    sort(a.begin(),a.end(),cmp);
    cout<<a;
    return 0;
}
