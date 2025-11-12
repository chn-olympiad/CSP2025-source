#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    int n,m,i,j,q,s,w=0;
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    for(i=1;i<=n*m;i++){
        for(j=1;j<=i;j++){
            if(a[j]<a[j+1]){
                q=a[j];
                a[j]=a[j+1];
                a[j+1]=q;
            }
        }
    }for(i=1;i<=n*m;i++){
        if(s==a[i]){
            s=i;
            break;
        }
    }for(i=1;i<=m;i++){
        if(a[i*n]<=a[s]){
            cout<<i<<" ";
            break;
        }
    }i--;
    if(i%2==1){
        for(j=n-1;j>=0;j--){
            if(a[i*n-j]==a[s]) cout<<n-j;
        }
    }
    else{
        i++;
        for(j=0;j<=n-1;j++){
            if(a[i*n-j]==a[s]) cout<<n-j;
        }
    }
    return 0;
}
