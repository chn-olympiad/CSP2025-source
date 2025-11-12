#include <bits/stdc++.h>
using namespace std;
int main(){
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int b[100]={};
for(int i=0;i<a.size();i++){
if(a[i]>="0||a[i]<=9){
a[i]=b[i];
}
int n=b.size();
sort(b,b+n);
for(int i=n;i>0;i--){
cout<<b[i];
}
fclose(stdin);
fclose(stdout);
return 0;
}
