#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=1;i<=len;i++)
    a[i]=s[i];
len=s.size();
sort(a+1,a+1+len);
for(int i=len;i>=1;i--)
    cout<<a[i];
return 0;}
