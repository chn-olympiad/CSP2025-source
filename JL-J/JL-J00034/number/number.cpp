#include<bits/stdc++.h>
using namespace std;
int n[1000005],pos;
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
cin>>s;
for(int i=0;i<s.size();i++){

if(s[i]<='9'&&s[i]>='0')
n[pos++]=s[i]-'0';
}
sort(n,n+pos);
for(int i=pos-1;i>=0;i--){
cout<<n[i];}

return 0;
}
