#include <bits/std c++.h>
using namecape std;
int a[5005];
int main{
    int n,q=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
    if(a[i]>a[j]){
    swap(a[i],a[j]);
    }
    }
    }
    for(int i=1;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    for(int y=j+1;y<=n;y++){
    if(a[i]+a[j]+a[y]>a[y]*2){
    q++;
    }
    }
    }
    }
    cout<<q;
    return 0;
    }

