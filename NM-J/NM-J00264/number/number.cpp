#include<bits/stdc++.h>
using namespace std;
char a[100010];
int b,d=1,c[100010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
b=strlen(a);
for(int i=0;i<b;i++){
if(a[i]=='0'){
c[d]=0;
d++;
}
if(a[i]=='1'){
c[d]=1;
d++;
}
if(a[i]=='2'){
c[d]=2;
d++;
}
if(a[i]=='3'){
c[d]=3;
d++;
}
if(a[i]=='4'){
c[d]=4;
d++;
}
if(a[i]=='5'){
c[d]=5;
d++;
}
if(a[i]=='6'){
c[d]=6;
d++;
}
if(a[i]=='7'){
c[d]=7;
d++;
}
if(a[i]=='8'){
c[d]=8;
d++;
}
if(a[i]=='9'){
c[d]=9;
d++;
}
}
for(int i=1;i<d;i++){
for(int j=i+1;j<d;j++){
if(c[i]<c[j]){
b=c[i];
c[i]=c[j];
c[j]=b;
}
}
}
for(int i=1;i<d;i++){
cout<<c[i];
}
return 0;
}

