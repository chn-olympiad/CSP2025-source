#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c,r;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int s=1;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
for(int i=1;i<=n*m;i++){

    if(a[i]>a[1]){
        s++;
    }
}
if(s<=n){
        c=1;
        r=s;
    cout<<c<<" "<<r;
}
if(s>n){
    if(s%n!=0){
        if((s/n)%2==0){
                c=s/n+1;
                r=s%n;
            cout<<c<<" "<<r;
        }else{
            c=s/n+1;
            r=n+1-s%n;
            cout<<c<<" "<<r;
        }
    }

    if(s%n==0){
        if((s/n)%2==0){
                c=s/n;
                r=1;
            cout<<c<<" "<<r;
        }else{
            c=s/n;
            r=n;
            cout<<c<<" "<<r;
        }
    }
}
return 0;
}
