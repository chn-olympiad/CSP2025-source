#include <bits/stdc++.h>
using namespace std;
int maxx[100000][2];
int numa[10000][2];
int numb[10000][2];
int numc[10000][2];
int t;
int n;
int b;
int a[100000][3];
void cx(){
    cin>>n;
for(int j=0;j<n;j++){
for(int k=0;k<3;k++){
cin>>a[j][k];
}
}
for(int j=0;j<n;j++){
for(int k=0;k<3;k++){
if(maxx[j][0]<a[j][k])
maxx[j][0]=a[j][k];
maxx[j][1]=k;
}
if(maxx[j][1]==0){
numa[0][0]++;numa[j][1]=maxx[j][0];}
if(maxx[j][1]==1){
numb[0][0]++;numb[j][1]=maxx[j][0];}
if(maxx[j][1]==2){
numc[0][0]++;numc[j][1]=maxx[j][0];}
for(int j=0;j<n ;j++){
if(numa[j][1]<numa[j+1][1])
swap(numa[j][1],numa[j+1][1]);
if(numb[j][1]<numb[j+1][1])
swap(numb[j][1],numb[j+1][1]);
if(numc[j][1]<numc[j+1][1])
swap(numc[j][1],numc[j+1][1]);
}
for(int j=0;j<n /2;j++){
b=numa[j][1]+numb[j][1]+numc[j][1];
}
cout<<b<<endl;
}}
int main(){
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);

cin>>t;



for(int i=0;i<t;i++){
 cx();
}
return 0;
}

