#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum;
    int a[5005];
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    if(a[j]+a[k]+a[l]==2*a[j] || a[j]+a[k]+a[l]==2*a[k] || a[j]+a[k]+a[l]==2*a[l]){
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum/30;
}
