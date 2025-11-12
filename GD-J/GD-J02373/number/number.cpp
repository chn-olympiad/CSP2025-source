#include<bits/stdc++.h> 
using namespace std;
int a[100],m,n,x,y;
float r;
int main(){
freopen("seat.in","r",stdin);	
freopen("seat.out","w",stdout);	
cin>>n>>m;
for(int i=0;i<n*m;i++){
cin>>a[i];
}	
r=a[0];
for(int i=0;i<n*m;i++){
for(int j=0;j<m*n;j++){
if(a[j]<a[j+1]){
swap(a[j],a[j+1]);
}
}
}		
for(int j=0;j<m*n;j++){
if(a[j]==r){
r=j+1;
}
}
y=ceil(r/n);
int r=r;
if((y%2==0)||(y%2!=0&&r%n==0)){
x=n-r%n;
}
else{
x=r%n;
}

cout<<y<<" "<<x;
fclose(stdin);	
fclose(stdout);	
return 0;
}

























