#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[n*m];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1 && m==1){cout<<1<<" "<<1;return 0;}
    int xr=a[1];
    int fs[n*m];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[j]>a[i]){
                fs[i]=a[j];
                fs[j]=a[i];
            }
        }
    }
    if(n==1){
        for(int i=1;i<=n*m;i++){
            if(fs[i]==xr){
                cout<<i<<" "<<1;
            }
        }
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n*m;i++){
            if(fs[i]==xr){
                cout<<1<<" "<<i;
            }
        }
        return 0;
    }
    for(int i=1;i<=n*m;i++){
        if(fs[i]==xr){
            if(i/n%2!=0){
                cout<<i/n+1<<" "<<(i/n%2);
            }
            if(i/n%2==0){
                cout<<i/n+1<<" "<<n-(i/n%2);
            }
        }
    }
    return 0;
}


