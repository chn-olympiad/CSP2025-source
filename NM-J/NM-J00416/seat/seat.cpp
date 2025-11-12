#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int m,n,s[11][11],v[101]={0},b,x,y,g,l,f;
cin>>n>>m;
l=m*n;
int i;
for( i=1;i<=l;i+=1 ){
    cin>>v[i];
}
g=v[1];
for( i=1;i<=l;i+=1 ){
for( int p=1;p<=l;p+=1 ){
    if(v[i]>v[i+1]){
        f=v[i];
        v[i]=v[i+1];
        v[i+1]=f;
    }
}
}
for( int i=1;i<=m;i++ ){
    if(i%2==0){
        for(int p=n;p>=0;p--){
    s[i][p]=v[b];
    b++;
}
    }else{
    for(int p=1;p<=n;p++ ){
     s[i][p]=v[b];
    b++;
}
    }
}

for( int i=1;i<=m;i++ ){
    for(int p=1;p<=n;p++ ){
     if(s[i][p]==g){
       x=i;
       y=p;
       break;
     }
}
    }
cout<<x<<"  "<<y;
return 0;
}
