#include<bits/stdc++.h>
using namespace std;
long long n[5],a[100000][3];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
int t;
cin>>t;
for(int a=0;a<t;a++){
cin>>n[a];
int m;
m=n[a];
for(int p=0;p<m;p++){
for(int q=0;q<3;q++){
cin>>a[p][q];
}
}
for(int p=0;p<m;p++){
 int z=0;
 if(a[p][0]==0&&a[p]a[2]==0){
    z++;
 }
  if(z==m){
    sort(a[0][1],a[m][1]);
    int g=0;
    for(int f=0;f<m/2;f++){
       g=g+a[f][1];
    }
    cout<<g;
  }
}
int i,j,k,l,b,c;
i=j=k=l=b=c=0;
for(int r=0;r<m;r++){
if(a[m][0]>a[m][1]&&a[m][0]>a[m][2]){
i++;
l=l+a[m][0];
}
if(a[m][1]>a[m][0]&&a[m][1]>a[m][2]){
j++;
b=b+a[m][1];
}
if(a[m][2]>a[m][0]&&a[m][2]>a[m][1]){
k++;
c=c+a[m][2];
}
}
if(i>j&&i>k){
if(i<=m/2){
cout<<l+b+c<<endl;}
cout<<4<<endl;
}
}
if(j>k&&j>i){
if(j<=m/2){
cout<<l+b+c<<endl;}
cout<<13<<endl;
}
if(k>j&&k>i){
if(k<=m/2){
cout<<l+b+c<<endl;}
cout<<21<<endl;
}
return 0;
}
