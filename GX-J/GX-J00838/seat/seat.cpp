#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a,p[111]={};
cin>>a;
p[0]=a;
for(int i=1;i<n*m;i++){
    cin>>p[i];
}
sort(p,p+n*m);
int y;
for(int i=n*m-1;i>=0;i--){
    if(p[i]==a)y=n*m-i-1;
}
int h=1,l=1,f=1;
while(y--){
if(l+f==0||l+f>n){
    h++;
    f*=-1;
}l+=f;}
cout<<h<<' '<<l;
return 0;
}

