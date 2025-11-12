#include <bits/std c++.h>
using namecape std;
int a[105];
int main{
    int n,m,x,y,q=1;
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
    cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
    for(int j=i+1;j<=n*m;j++){
    if(a[i]<a[j]){
    swap(a[i],a[j]);
    if(i==q){
    q=i;
    }else if(j==q){
    q=j;
    }
    }
    }
    }
    if(q%n==0){
    if(q/n%2==0){
    y=0;
    x=a[1]/n;
    }else{
    y=n;
    x=q/n;
    }
    }
    if(q/n%2==0){
    x=q/n+1;
    y=q%n;
    }
    else{
    x=q/n+1;
    y=n-q%n;
    }
    cout<<x<<" "<<y;
    return 0;
    }

