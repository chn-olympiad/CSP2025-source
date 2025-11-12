/*
*/
#include<bits/stdc++.h>
using namespace std;
string s;
string c;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            c+=s[i];
        }
    }
    sort(c.begin(),c.end(),cmp);
    cout<<c;
    return 0;
}
