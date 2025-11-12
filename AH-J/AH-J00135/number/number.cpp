#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
int lena=0;
cin>>s;
for(unsigned int i=0;i<s.size();i++)
if((s[i]-48)<10&&s[i]>=48) a[lena++] = s[i]-48;
sort(a,a+lena);
if(a[lena-1]==0) cout<<0;
else for(int i=lena-1;i>=0;i--) cout<<a[i];
return 0;
}
