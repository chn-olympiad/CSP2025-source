#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int m,n,r,w,x,s;
int a[200];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
w=m*n;
for(int i=0;i<w;i++){
cin>>a[i];
}
r=a[0];
for(int i=0;i<w;i++){
for(int j=i+1;j<w;j++){
s=a[i];
if(s<a[j]){
s=a[j];
a[j]=a[i];
a[i]=s;
}	
}
}
for(int i=0;i<w;i++){
if(r==a[i]){
x=i;
break;
}	
}
if((x/n)%2!=0){
	cout<<x/n<<x%n;
}
else{
cout<<x/n<<m-(x%n);
}	
return 0;
}
