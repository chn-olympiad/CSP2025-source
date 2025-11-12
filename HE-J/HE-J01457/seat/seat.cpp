#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a[15][15],c,b[105],d;
int n,m;
cin>>n>>m;
cin>>b[0];c=b[0];
for(int i=1;i<n*m;i++){
    cin>>b[i];
}
for(int i=0;i<n*m;i++){
    for(int j=0;j<n*m-i-1;j++){
        if(b[j+1]>b[j]) swap(b[j+1],b[j]);
    }
}
for(int i=0;i<n*m;i++){
    if(b[i]==c) d=i;
}
int l,h;
if(d/n%2==0){
    l=d/n+1;
    h=d%(n*2)+1;
}
else {
 l=d/n+1;
 h=2*n-d%(n*2);
}
cout<<l<<' '<<h;
return 0;
}
