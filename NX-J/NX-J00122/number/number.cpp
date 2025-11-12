#include <bits/stdc++.h>
using namespace std;
long long s=0,d;
long long a[999999];
string f;
bool cmp(int i){
a[i+1]>a[i];
}
int main(){
    freopen("number4.in","r",stdin);
    freopen("number.out","w",stdout);
cin>>f;
for(int i=0;i<=f.size();i++){
if(f[i]>='0' && f[i]<='9'){
a[s]=f[i]-'0';
s++;
}
}
for(int i=0;i<s;i++){
for(int j=0;j<s;j++){
if(a[j]<a[j+1]){
swap(a[j],a[j+1]);
}
}
}
for(int i=0;i<s;i++){
cout<<a[i];
}

return 0;
}
