#include<bits/stdc++.h>
using namespace std;
long long t,n,ai1,ai2,ai3,m,a1,a2,a3;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);	
cin>>t;
int a[100];
for(int i=1;i<=t;i++){
m=0;
cin>>n;
a1=0;
a2=0;
a3=0;
for(int i=1;i<=n;i++){	
cin>>ai1>>ai2>>ai3;
if(ai1>ai2&&ai1>ai3){
a1++;
if(a1>n/2){
if(ai2>ai3&&a2<n/2){
m+=ai2;
a2++;
a1--;
}
if(ai3>ai2&&a3<n/2){
m+=ai3;
a3++;
a1--;
}	
}
}
else{
m+=ai1;	
}
if(ai2>ai1&&ai2>ai3){
a2++;
if(a2>n/2){
if(ai1>ai3&&a1<n/2){
m+=ai1;
a1++;
a2--;
}
if(ai3>ai1&&a3<n/2){
m+=ai3;
a3++;
a2--;
}	
}	
else{
m+=ai2;	
}}
if(ai3>ai2&&ai3>ai1){
a3++;
if(a3>n/2){
if(ai2>ai1&&a2<n/2){
m+=ai2;
a2++;
a3--;
}
if(ai1>ai2&&a1<n/2){
m+=ai1;
a1++;
a3--;
}	
}	
else{
m+=ai3;	
}}
}
a[i]=m;
}
for(int i=1;i<=t;i++){
cout<<a[i]<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
