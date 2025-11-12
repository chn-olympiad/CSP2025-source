#include<bits/stdc++.h>
using namespace std;
string h[12];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0') h[0]+='0';
        if(s[i]=='1') h[1]+='1';
        if(s[i]=='2') h[2]+='2';
        if(s[i]=='3') h[3]+='3';
        if(s[i]=='4') h[4]+='4';
        if(s[i]=='5') h[5]+='5';
        if(s[i]=='6') h[6]+='6';
        if(s[i]=='7') h[7]+='7';
        if(s[i]=='8') h[8]+='8';
        if(s[i]=='9') h[9]+='9';
    }
    for(int i=9;i>=0;i--){
        cout<<h[i];
    }
    cout<<endl;
    return 0;
}
