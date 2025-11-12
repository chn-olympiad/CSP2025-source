#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,type;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int act=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==act){
            type=i;
        }
    }
    int ny=type%(2*n),ky=type/n;
    if(type%n!=0){
        ky+1;
    }
    if(ny<=n){
        cout<<ky+1<<" "<<ny;
    }else{
        cout<<ky+1<<" "<<2*n+1-ny;
    }

    return 0;
}
