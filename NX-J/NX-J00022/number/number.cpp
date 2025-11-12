#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
int b=0,c=0;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]-'0'<=9 and s[i]-'0'>=0){
        if(s[i]-'0'==0)
            c++;
        a[b]=s[i]-'0';
        b++;}}
sort(a,a+s.size());
for(int i=s.size();i>=0;i--)
    if(a[i]!=0)
        cout<<a[i];
for(int i=1;i<=c;i++)
    cout<<0;
return 0;
}
