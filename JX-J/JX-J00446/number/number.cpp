#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k;
int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
int main(){
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]-'0'>=0 and s[i]-'0'<=9){
            k++;
            if(s[i]-'0'==0) a0++;
            else if(s[i]-'0'==1) a1++;
            else if(s[i]-'0'==2) a2++;
            else if(s[i]-'0'==3) a3++;
            else if(s[i]-'0'==4) a4++;
            else if(s[i]-'0'==5) a5++;
            else if(s[i]-'0'==6) a6++;
            else if(s[i]-'0'==7) a7++;
            else if(s[i]-'0'==8) a8++;
            else if(s[i]-'0'==9) a9++;
        }
    }
    for(int i=1;i<=a9;i++){
        cout<<9;
    }
    for(int i=1;i<=a8;i++){
        cout<<8;
    }
    for(int i=1;i<=a7;i++){
        cout<<7;
    }
    for(int i=1;i<=a6;i++){
        cout<<6;
    }
    for(int i=1;i<=a5;i++){
        cout<<5;
    }
    for(int i=1;i<=a4;i++){
        cout<<4;
    }
    for(int i=1;i<=a3;i++){
        cout<<3;
    }
    for(int i=1;i<=a2;i++){
        cout<<2;
    }
    for(int i=1;i<=a1;i++){
        cout<<1;
    }
    for(int i=1;i<=a0;i++){
        cout<<0;
    }
    return 0;
}
