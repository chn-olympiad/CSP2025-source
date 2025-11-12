#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int b,c,d=0;
int n,m;
cin>>n>>m;
int a[m*n+1];
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
for(int i=1;i<=n*m+1;i++){
    if(a[i]>a[1]){
        d++;
    }
}
b=d%n;
c=d/n;
cout<<c+1<<" ";
if(c%2==1){
    cout<<n-b+1;
}else{
    cout<<b;
}
//cout<<"a";
return 0;
}
