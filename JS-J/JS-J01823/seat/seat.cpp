#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[202];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int as=0;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
    if(i==1)as=a[i];
}
sort(a+1,a+1+n*m,greater<int>());
int d;
for(int i=1;i<=n*m;i++){
    if(a[i]==as){
        d=i;
        break;
    }
    if(a[n*m-i]==as){
        d=n*m-i;
        break;
    }
}
if(d<=n){
    cout<<1<<' '<<d;
}
else{
    int x=d%n;
    int y=d/n;
    if(x==0){
        y--;
    }
    if(y%2==0){
        cout<<y+1<<' '<<x;
    }
    else{
        cout<<y+1<<' '<<n-x+1;
    }
}
  return 0;
}
