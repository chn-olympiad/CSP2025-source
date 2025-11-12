#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,z=0,j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            if(s[i]=='0') a++;
            else if(s[i]=='1') b++;
            else if(s[i]=='2') c++;
            else if(s[i]=='3') d++;
            else if(s[i]=='4') e++;
            else if(s[i]=='5') f++;
            else if(s[i]=='6') g++;
            else if(s[i]=='7') h++;
            else if(s[i]=='8') z++;
            else j++;
        }
    }
    while(j--) cout<<9;
    while(z--) cout<<8;
    while(h--) cout<<7;
    while(g--) cout<<6;
    while(f--) cout<<5;
    while(e--) cout<<4;
    while(d--) cout<<3;
    while(c--) cout<<2;
    while(b--) cout<<1;
    while(a--) cout<<0;
    return 0;
}
