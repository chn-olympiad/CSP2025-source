#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen<"number1.in",'i',>
    freopen<"number1.ans",'w'>
    string s;
    cin>>s;
    int i,a,m=0;
    while(s[i]!='\0'){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            if(i<m) m=i;
            a+=m;
        }
    }
}