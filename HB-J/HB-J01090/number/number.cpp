#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string s,a;
    cin>>s;
    for(int i=9;i>=0;i--){
        if(i==9) a="9";
        if(i==8) a="8";
        if(i==7) a="7";
        if(i==6) a="6";
        if(i==5) a="5";
        if(i==4) a="4";
        if(i==3) a="3";
        if(i==2) a="2";
        if(i==1) a="1";
        if(i==0) a="0";
        for(int i=0;i<=s.size()-1;i++){
            if(s[i]==a[0])cout<<s[i];
        }
    }
}
