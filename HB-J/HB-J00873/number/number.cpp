#include<bits/stdc++.h>
using namespace std;
string s,a,b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i]=' ';
        }
        else{
            a[i]=s[i];
        }
    }
    for(int i=0;i<s.size();i++){
        if(a[i]!=' '){
            b[i]=a[i];
        }
    }
    for(int i=0;i<s.size();i++){
        cout<<b[i];
    }

}
