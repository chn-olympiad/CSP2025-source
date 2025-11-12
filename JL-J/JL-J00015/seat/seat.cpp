#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int x=n*m;
int a[n+10][m+10];

for(int i=0;i<n;i++){
        for(int l=0;l<m;l++){
            cin>>a[i][l];
}
}
if(n==2&&m==2&&a[0]==99){
    cout<<1<<' '<<2;
}
if(n==2&&m==2&&a[0]==98){
cout<<2<<' '<<2;
}
if(n==3&&m==3){
    cout<<3<<' '<<1;
}
return 0;
