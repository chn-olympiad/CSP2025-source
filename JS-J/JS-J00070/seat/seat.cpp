#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w".stdout);
    int n,m,a[123],p=0,z,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p+=1;
            cin>>a[p];
        }
    }
    z=a[1];
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            if(a[j]<a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=p;i++){
        if(a[i]==z){
            x=i;
        }
    }
    int k=x-1,l=1;
    while(1){
        if(k-n<0)break;
        k-=n;
        l+=1;
    }
    if(l%2!=0){
        cout<<l<<' '<<k+1;
    }
    else{
        cout<<l<<' '<<n-k;
    }
    return 0;
}
