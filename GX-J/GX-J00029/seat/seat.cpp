#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101],s,b,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        s=a[1];}
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){
                a[i]=b;
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(s==a[i]){
            c=(i+n-1)/n;
            s=i;
        }
    }
    if(c%2==1){
        for(int i=1;i<=n-1;i++){
            s==n*(c-1)+1+i;
            r++;
        }
    }
    else {
        for(int i=1;i<=n-1;i++){
            s==c*n-i;
            r++;
        }
    }
    cout<<c+1<<" "<<r+1;
   return 0;
}
