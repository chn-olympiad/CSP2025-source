#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a[10],b;

    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0'){
                a[0]+='0';
            }
            if(s[i]=='1'){
                a[1]+='1';
            }
            if(s[i]=='2'){
                a[2]+='2';
            }
            if(s[i]=='3'){
                a[3]+='3';
            }
            if(s[i]=='4'){
                a[4]+='4';
            }
            if(s[i]=='5'){
                a[5]+='5';
            }
            if(s[i]=='6'){
                a[6]+='6';
            }
            if(s[i]=='7'){
                a[7]+='7';
            }
            if(s[i]=='8'){
                a[8]+='8';
            }
            if(s[i]=='9'){
                a[9]+='9';
            }
        }
    }
    b+=a[9];
    b+=a[8];
    b+=a[7];
    b+=a[6];
    b+=a[5];
    b+=a[4];
    b+=a[3];
    b+=a[2];
    b+=a[1];
    b+=a[0];
    cout<<b;
    return 0;
}
