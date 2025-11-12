#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,max,ans;
int a[n+1];
int one,two,three;
for(int z=0;z<t;z++){
for(int j=0;j<n;j++){
for(int y=1;y<3;y++){
if(a[y]<a[y+1]){
a[y]=max;
}
else{
a[y+1]=max;
}
if(a[1]==max)one++;
if(a[2]==max)two++;
if(a[3]==max)three++;
if(one>n/2){
sort(a.begin(),a.end());
max=a[2];
}
if(two>n/2){
sort(a.begin(),a.end());
max=a[2];
}
if(three>n/2){
sort(a.begin(),a.end());
max=a[2];
}
ans+=max;
}
}
}
}
