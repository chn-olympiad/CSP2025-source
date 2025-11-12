#include<bits/stdc++.h>
using namespace std;
int a[165]={0};
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        ++a[s[i]];
    }
    for(int i='9';i>='0';--i){
        for(int j=a[i];j>0;--j){
            cout<<i-48;
        }
    }
    return 0;
}
