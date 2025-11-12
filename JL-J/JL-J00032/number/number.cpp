#include<bits/stdc++.h>
using namespace std;
string s;
int n,a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
int main(){
    freopen("number.cpp","r",stdin);
    freopen("number.cpp","w",stdout);
    for(int i=1;i<=n;i++){
        if(s[i]!='1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'||'0')
            continue;
        else if(s[i]=='9')
            a9+=1;
        else if(s[i]=='8')
            a8+=1;
        else if(s[i]=='7')
            a7+=1;
        else if(s[i]=='6')
            a6+=1;
        else if(s[i]=='5')
            a5+=1;
        else if(s[i]=='4')
            a4+=1;
        else if(s[i]=='3')
            a3+=1;
        else if(s[i]=='2')
            a2+=1;
        else if(s[i]=='1')
            a1+=1;
        else if(s[i]=='0')
            a0+=1;
    }
    for(int i=1;i<=a9;i++)
        cout<<'9';
    for(int i=1;i<=a8;i++)
        cout<<'8';
    for(int i=1;i<=a7;i++)
        cout<<'7';
    for(int i=1;i<=a6;i++)
        cout<<'6';
    for(int i=1;i<=a5;i++)
        cout<<'5';
    for(int i=1;i<=a4;i++)
        cout<<'4';
    for(int i=1;i<=a3;i++)
        cout<<'3';
    for(int i=1;i<=a2;i++)
        cout<<'2';
    for(int i=1;i<=a1;i++)
        cout<<'1';
    for(int i=1;i<=a0;i++)
        cout<<'0';
    return 0;
}
