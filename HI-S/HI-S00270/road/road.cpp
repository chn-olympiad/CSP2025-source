#include<bits/stdc++.h>
using namespace std;
int main(){
preopen("road.in","r",stdin);
preopen("road.out","w",stdout);
int n,m,k,a;
int h[10001],r[1000001],w[11];
cin>>n>>m>>k; 
for(int i=0;i<n;i++){
cin>>h[i];
}
for(int i=0;i<m;i++){
	cin>>r[i];
}
for(int i=0;i<k;i++){
cin>>w[i];
}
if(m==1){
cout<<0;
}
else{
if(m%2==0){
for(int i=0;i<m/2;i++){
if(r[i]<r[i+1]){
a=r[i];r[i]=2147483647;
}
}
}
else {
for(int i=0;i<(m+1)/2;i++){
if(r[i]<r[i+1]){
a=r[i];r[i]=2147483647;
}
}
}
}
cout<<a;


	
	

return 0;
}

