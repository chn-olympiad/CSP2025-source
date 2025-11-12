#include<bits/stdc++.h>
using namespace std;
string x;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'){
            x+=s[i];
        }
    }
    for(int i=0;i<=9;i++){
        a[i]='9'-i;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<x.size();j++){
            if(x[j]==a[i])cout<<x[j];
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
