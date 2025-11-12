#include<bits/stdc++.h>
using namespace std;
struct  l{int id,num;}num[200];
bool cmp(l a,l b){
return a.num>b.num;}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,x,p;
cin>>n>>m;
x=n*m;
for(int i=0;i<x;i++){
cin>>num[i].num;
num[i].id=i+1;
}
sort(num,num+x,cmp);
for(int i=0;i<x;i++){
if(num[i].id==1)
p=i;

}
cout<<p/n+1<<" "<<(p%n%2==1?m-p%n:p%n)+1;
}
