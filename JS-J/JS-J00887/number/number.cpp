#include <bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        int b=s[i]-'0';
        if(b>=0 && b<=9)a[b]+=1;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
             cout<<i;
        }
    }
    return 0;
}
