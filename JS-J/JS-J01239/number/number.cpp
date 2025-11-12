#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[11]={0};
    string s;
    cin>>s;
    for(int i=0;i<=s.length();i++){
         if(s[i]>=48&&s[i]<=57){
            a[s[i]-48]=a[s[i]-48]+1;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>0;j--)
            cout<<i;
    }
    return 0;
}
