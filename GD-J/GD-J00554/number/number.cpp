#include<bits/stdc++.h> 
using namespace std;
char a[1000005];
long long b[10],c;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
c=strlen(a);
for(long long i=0;i<c;i++){
if(a[i]>='0' && a[i]<='9'){
b[a[i]-'0']++;
}
}
for(long long i=9;i>=0;i--){
for(long long j=0;j<b[i];j++){
cout<<i;
}
}
return 0;
}
