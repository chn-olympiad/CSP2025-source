#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,r,c,nr,mr;
cin>>n>>m;
float a[400];
for(int i=0;i<m*n;i++){
cin>>a[i];
}
r=a[0];
for(int i=0;i<m*n;i++){
for(int o=0;o<m*n-1;o++){
if(a[o]<a[o+1]){
c=a[o];
a[o]=a[o+1];
a[o+1]=c;
}
}
}
for(int i=0;i<m*n;i++){
if(a[i]==r){
r=i+1;
break;
}
}
if(r%n!=0){
mr=r/n+1;
}
else{
mr=r/n;
}
if(mr%2==0){
if(r%n==0){
nr=1;
}
else{
nr=n-r%n+1;
}
}  
else{
if(r%n==0){
nr=n;
}
else{
nr=r%n;	
}
}
cout<<mr<<" "<<nr;
fclose(stdin);fclose(stdout);
return 0;
} 
