#include<bits/stdc++.h>
using namespace std;
int a[400],b[200][200];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,x,y,z;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    y=a[1];
    for(int i=1;i<=n*m-1;i++){
        if(a[i]<a[i+1]){
            x=a[i];
            a[i]=a[i+1];
            a[i+1]=x;
        }
        if(i!=1){
            if(a[i-1]<a[i]){
                x=a[i-1];
                a[i-1]=a[i];
                a[i]=x;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(y==a[i]){
            z=i;
        }
    }
    if(z%n!=0){
        if(z/n%2==1){
            c=z/n+1;
            r=n-z%n+1;
        }
        else{
            c=z/n+1;
            r=z%n;
        }
    }
    else{
        if(z%n==0){
            c=z/n;
            if(z/n%2==0){
                r=1;
            }
            else{
                r=n;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}

