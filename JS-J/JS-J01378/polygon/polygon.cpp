#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void itCan(int p,int q){
    int mx=0,z=0;
    for(int i=p;i<=q;i++){
        z+=a[i];
        if(a[i]>mx){
            mx=a[i];
        }
    }
    if(z>(mx*2)){
        ans++;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-i-2;j++){
                for(int k=i+j+2;k<n;k++)
                    itCan(i,k);
        }
    }
    cout<<ans;
    return 0;
}


