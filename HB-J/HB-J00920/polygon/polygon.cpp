#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            sum[i]=a[i]+a[j];
            for(int k=j+1;k<=n;k++){
                sum[i]+=a[k];
                if(sum[i]>a[k]*2){
                    ans+=n-k+1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
