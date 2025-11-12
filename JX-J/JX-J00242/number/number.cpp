#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,m;
string s,string1="",string2="",string3="",string4="",string5="",string6="",string7="",string8="",string9="",string0="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') string0+='0';
        if(s[i]=='1') string1+='1';
        if(s[i]=='2') string2+='2';
        if(s[i]=='3') string3+='3';
        if(s[i]=='4') string4+='4';
        if(s[i]=='5') string5+='5';
        if(s[i]=='6') string6+='6';
        if(s[i]=='7') string7+='7';
        if(s[i]=='8') string8+='8';
        if(s[i]=='9') string9+='9';
    }
    cout<<string9<<string8<<string7<<string6<<string5<<string4<<string3<<string2<<string1<<string0;
    return 0;
}
