#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int b=a[1];
    for(int i=1;i<=m*n;i++){
        for(int j=i+1;j<=m*n;j++){
            if(a[j]>a[i]){
                int c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
    int x;
    for(int i=1;i<=m*n;i++){
        if(b==a[i]){
            x=i;
        }
    }
    int c,r;
    if(c>=n){
        if(c%n==0){
            c=x/n;
        }else{
            c=x/n+1;
        }
    }else{
        c=1;
    }
    r=x%n;
    if(r==0){
        r=n;
    }
    if(c%2==1){
        cout<<c<<" "<<r;
    }else{
        cout<<c<<" "<<n-r+1;
    }
    return 0;
}
