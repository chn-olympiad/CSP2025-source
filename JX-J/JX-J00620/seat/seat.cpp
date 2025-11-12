#include<bits/stdc++.h>
using namespace std;
long long a[1001],n,m,p,s[50][50],t;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }p=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                t++;s[j][i]=a[t];
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                t++;s[j][i]=a[t];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==p){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}

