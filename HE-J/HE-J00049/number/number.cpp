#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long b[1003];
    long long b1=0,b2=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            b[b1]=s[i]-48;
            b1++;
        }
    }
    long long y;
    bool f=1;
    while(f){
        f=0;
        for(int i=0;i<b1;i++){
            if(b[i]<b[i+1]){
                y=b[i];
                b[i]=b[i+1];
                b[i+1]=y;
                f=1;
            }
        }
    }
    for(int j=0;j<b1;j++){
        cout<<b[j];
    }
    return 0;
}
