#include<bits/stdc++.h>
using namespace std;
char l;
string s,a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            a+=s[i];
        }
    }
    for(int i=0;i<a.length();i++){
        for(int j=0;j<a.length();j++){
            if(int(a[j])<int(a[j+1])){
                l=a[j];
                a[j]=a[j+1];
                a[j+1]=l;
            }
        }
    }
    cout<<a;
    return 0;
}
