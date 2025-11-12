#include<bits/stdc++.h>
using namespace std;
int a[10];
string t;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>t;
for(int i=0;i<t.size();i++){
    if(t[i]>=48&&t[i]<=57)a[t[i]-'0']++;
}
for(int i=9;i>=0;i--){
    for(int j=1;j<=a[i];j++)cout<<i;
}
return 0;
}
