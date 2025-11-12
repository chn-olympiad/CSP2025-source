#include<bits/stdc++.h>
using namespace std;
int n,m,a[400],e,r,b[400];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
e=a[1];
sort(a+1,a+1+n*m);
if(e==a[n*m]){
    cout<<1<<" "<<1;
    return 0;
}
int o=1;
for(int i=n*m;i>=1;i--){
    if(a[i]==e){
        r=o;
        break;
    }
    o++;
}
if(r<=n){
    cout<<1<<" "<<r;
    return 0;
}
int x=r%n,y=r/n;
if(x==0){
    if(y%2==0){
        cout<<y<<" "<<1;
    }
    else if(y%2!=0){
        cout<<y<<" "<<n;
    }
}
else if(x!=0){
    if(y%2!=0){
        cout<<y+1<<" "<<n-x+1;
    }
    else if(y%2==0){
        cout<<y+1<<" "<<x;
    }
}
return 0;
}
