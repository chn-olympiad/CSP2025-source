#include<bits/stdc++.h>
using namespace std;
int k[12][12];
int main(){
    int n,m,b=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>k[n][m];
            if(k[n][m]>k[1][1]){
                b++;
            }
        }
    }
    int l=b/n,r=b%n;
    if(l%2==0&&r!=0){
        cout<<r<<" "<<l;
    }
    if(l%2==0&&r==0){
        cout<<r<<" "<<l+1;
    }
    if(l%2==1&&r!=0){
        cout<<n-r<<" "<<l;
    }
    if(l%2==1&&r==0){
        cout<<n-r<<" "<<l+1;
    }
    return 0;
}
