#include<bits/stdc++.h>
using namespace std;
int zong;
int lu;
char a[]={};
char nai[]={};
int sum;
int max;
int main( ){
cin>>zong>>lu;
for(int i=1;i<=zong;i++){
      cin>>a[i];
}
for(int i=1;i<=zong;i++){
     cin>>nai[i];
}
for(int i=1;i<=lu;i++){
if(nai[i]=0){
zong-=1;
}else{
if(a[i]==0){
zong-=1;
}
}
if(zong==lu){
sum++;
}else{
sum+=0;
}
}
cout<<sum;
return 0;
}