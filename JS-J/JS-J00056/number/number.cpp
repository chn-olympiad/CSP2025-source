#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
long long a[10000],ll=0;
long long k=s.size();
for(long long i=0;i<k;i++){
if(s[i]>='0' && s[i]<='9'){
ll++;
a[ll]=s[i]-'0';
 }
}
sort(a+1,a+ll+1);
for(int i=ll;i>0;i--) cout<<a[i];

return 0;
}
