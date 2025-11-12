#include <bits/stdc++.h>
using namespace std;
int a[105];
int main( ){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,b=0,x,y,z;
    cin>>n>>m;
    b=m*n;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    int s=0;
    s=a[1];
    for(int i=1;i<=b;i++){
        for(int j=1;j<=b-i;j++)
        if(a[j]<a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=b;i++){
        if(a[i]==s){
            x=i;
            break;
        }
    }
    if(n==1){
        cout<<x<<" "<<1;
    }
    else if(m==1){
        cout<<1<<" "<<x;
    }
    else{
        if(x%n==0){
            y=x/n;
            if(y%2==0){
                z=1;
            }
            else{
                z=n;
            }
        }
        else{
            y=x/n+1;
            if(y%2==0){
                z=n-x%n+1;
            }
            else{
                z=x%n;
            }
        }
        cout<<y<<" "<<z;
    }

    return 0;
}
