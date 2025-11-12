#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
long long a[1000000];
for(int i=0;i<=s.size();i++){
    if(s[i]==0||s[i]==1||s[i]==2|s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9){
        a[i]=s[i];
    }
}
sort(a[0],a[s.size()]);
for(int i=s.size();i>=0;i--){
    cout<<a[i];
}


return 0;
}
