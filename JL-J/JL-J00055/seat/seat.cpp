#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],b,c,r,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==b){
                d=n*m-i+1;
                break;
        }
    }
    c=d/n;
    if(c%2==0&&c!=0&&d%n!=0){
        r=d%n;
        c=c+1;
    }
    else if(c%2==1&&d%n!=0){
        r=n-(d%n-1);
        c=c+1;
    }
    else if(c==0){
        c=1;
        r=d;
    }
    else if(d%n==0){
        if(c%2==0)r=1;
        if(c%2==1)r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}
