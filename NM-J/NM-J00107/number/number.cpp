#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
int a[1000005],n=0,r=0;
cin>>s;
for(int i=0;i<s.length();i++){
    if(s[i]-'0'>=0&&s[i]-'0'<=9){
        a[r]=s[i]-'0';
        r++;
    }
}
for(int i=9;i>=0;i--){
   for(int j=0;j<r;j++){
        if(a[j]==i){
        cout<<i;
        }

    }
}
return 0;
}
