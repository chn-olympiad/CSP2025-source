#include<bits/stdc++.h>
using namespace std;
int n,m,k,p=0;
int a[600],c[600][600];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    k=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>k){
            p++;
        }
    }
    int ans=0,z=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
        for(int j=1;j<=n;j++){
            if(ans==p){
                cout<<i<<" "<<j;
                z=1;
                break;
            }
            ans++;
        }
        }else{
        for(int j=n;j>=1;j--){
            if(ans==p){
                cout<<j<<" "<<i;
                z=1;
                break;
            }
            ans++;
        }
        }
        if(z==1){
            break;
        }
    }
    return 0;
}
