#include<bits/stdc++.h>
using namespace std;
void ans(int n,int){
for(int i=0;i<=n;i++){
for(int j=0;j<=3;j++){
cin>>mum[i][j];
}

}
return ;
}
void num(){
ans(n);

for(int i=0;i<=n;i++){
if(mum[i][0]>mum[i][1]&&mum[i][0]>mum[i][2]){
if(a<n/2){
club+=mum[i][0];
a++;
}
}
if(mum[i][1]>mum[i][0]&&mum[i][1]>mum[i][2]){
if(b<n/2){
club+=mum[i][1];
b++;
}
}
if(mum[i][2]>mum[i][1]&&mum[i][2]>mum[i][0]){
if(c<n/2){
club+=mum[i][2];
c++;
}
}
}
cout<<club<<endl;
return ;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,mum{n}[3],a=0,b=0,c=0,club=0;
cin>>t;
for(int i=1;i<=t,i++){
cin>>n;
num();
}

return 0;
}