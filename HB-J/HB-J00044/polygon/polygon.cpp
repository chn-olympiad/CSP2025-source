#include<bits/stdc++.h>
using namespace std;

int n,a[5010],numn=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if(a[k]<a[k+1])swap(a[k],a[k+1]);
        }
    }
    for(int l=0;l<n;l++){
        for(int m=0;m<n;m++){
            if(2*a[m+2]<a[l]+a[m+1]&&(m+2)<=n)numn+=1;
        }
    }
    cout<<numn;
    return 0;
}
