#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mc;
int asd(int x,int y){
if(x%y==0)return x/y;
return (x/y)+1;
}
int ms(int x,int y){
    if(x%y!=0)return x%y;
    return y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)cin>>a[i];
int t=a[1];
sort(a+1,a+1+n*m);
for(int i=1;i<=n*m;i++){
    if(a[i]==t){
         mc=n*m-i+1;
        break;
    }
}
int l=asd(mc,n);
if(l%2==0){
    cout<<l<<" "<<n-ms(mc,n)+1;
}
else cout<<l<<" "<<ms(mc,n);
return 0;
}
