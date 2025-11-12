#include<bits/stdc++.h>
using namespace std;
int a[15];
char x;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
   for(int i=0;i<s.size();i++){
       x=s[i];
        if(48<=int(x)<=57){
            a[int(x)-48]++;
        }
    }
    for(int i=10;i>0;i--){
        for(int j=1;j<=a[i-1];j++){
            cout<<i-1;
        }
    }
    return 0;
}
