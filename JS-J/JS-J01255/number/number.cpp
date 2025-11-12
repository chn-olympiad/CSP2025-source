#include<bits/stdc++.h>
using namespace std;
string s;
int js=0,a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i]))a[++js]=s[i]-'0';
    }
    sort(a+1,a+js+1);
    for(int i=js;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
