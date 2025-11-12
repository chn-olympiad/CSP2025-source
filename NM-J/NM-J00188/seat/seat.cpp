
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m=0;
cin>>n>>m;
int z=n*m;
int a[z];
for(int i=0;i<z;i++){
    cin>>a[i];
}
int p=a[0];
for(int i=0;i<z;i++){
   for(int j=0;j<z-1;j++){
   if(a[j]<a[j+1]){
        swap(a[j],a[j+1]);
    }
}
}
int od=0;
for(int i=0;i<z;i++){
    if(a[i]==p){
        od=i+1;
    }
}
int c,r=0;
if(od%n==0){
    r=od/n;
}
else{
    r=od/n+1;
}
if(r%2==1){
    if(od%r==0){
        c=n;
    }
    else{
        c=od%r;
    }
}
else{
     if(od%r==0){
        c=1;
    }
    else{
        c=n+1-od%r;
    }
}
cout<<r<<" "<<c;
return 0;
}
