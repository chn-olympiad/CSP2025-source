#include<bits/stdc++.h>
using namespace std;
string s;long long a[11];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]-48<=9&&s[i]-48>=0){
        a[s[i]-48]++;
    }
}
for(int j=9;j>=0;j--){
    while(a[j]>0){
        a[j]--;
        cout<<j;
    }
}
return 0;
}
