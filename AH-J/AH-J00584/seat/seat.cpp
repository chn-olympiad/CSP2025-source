#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
if(n<=1&&m<=1) cout<<1<<" "<<1;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
int aa=a[1];
sort(a+1,a+n+1);
int b[n*m+5]={};
for(int i=1;i<=m*n;i++){
    b[i]=a[n*m-i+1];
}
int i;
for(i=1;i<=n*m;i++){
    if(b[i]==aa) break;
}
int k=i/n,r=i%n;
if(r>0) k++;
if(n==2&&m==2){
    if(i==1) cout<<1<<" "<<1;
    if(i==2) cout<<1<<" "<<2;
    if(i==3) cout<<2<<" "<<2;
    if(i==4) cout<<2<<" "<<1;
}
else if(k%2==0){
    if(r==0) cout<<k<<" "<<1;
    else cout<<k<<" "<<n-r+1;
}
else if(k%2==1){
    if(r==0) cout<<k<<" "<<n;
    else cout<<k<<r+1;
}
return 0;
}
