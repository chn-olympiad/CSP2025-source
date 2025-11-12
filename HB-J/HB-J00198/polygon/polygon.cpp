#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxa;
 int main(){
 //   freopen("polygon.in","r",stdin);
 //   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(n==3){
        if(maxa*2<a[1]+a[2]+a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    else if(maxa==1){
        int ans=0;
        for(int i=3;i<n;i++){
            int sum=1;
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    sum*=(n-j-k);
                }
            }
            ans+=sum;
        }
        cout<<ans+1;
        return 0;
    }
    return 0;
}