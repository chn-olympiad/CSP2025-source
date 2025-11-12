#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,arr[5009]={},ans=0,k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=1){
            k=1;
        }
    }
    sort(arr,arr+n);
    if(n==3){
        if(arr[0]+arr[1]>arr[2]){
            cout<<1;
            return 0;
        }
    }
    if(k==0){
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                for(int o=0;o<i;o++){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
