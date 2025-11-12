#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
long long s=0;
cin>>a;
long long l=a.size();
long long b[l+5];
for(long long i=0;i<l;i++){
if(a[i]>='0'&&a[i]<='9'){
s++;
b[s]=a[i]-'0';
}
}
sort(b+1,b+s+1);
for(long long i=s;i>=1;i--)cout<<b[i];
return 0;
}
