#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a=0;
    cin>>s;

    for(int i=0;i<s.size();i++){
    if('0'<=s[i]&&s[i]<='9') a+=s[i];
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[i]<a[j]) swap(a[i],a[j]);
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }
return 0;
}
