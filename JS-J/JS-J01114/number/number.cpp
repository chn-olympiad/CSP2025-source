#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
cin>>s;
char a[s.length()];
for(int i=0;i<s.length();i++)
    a[i]=s[i];
sort(a,a+s.length());
for(int i=s.length()-1;i>=0;i--){
if(a[i]>47&&a[i]<58)
cout<<a[i];
}
return 0;
}
