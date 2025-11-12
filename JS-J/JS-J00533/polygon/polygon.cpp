#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long n,a[10000];
    cin>>n;
    for(long i=1;i<=n;i++){
        cin>>a[i];
    }long ans=0;
    for(long i=1;i<=n-2;i++){
        long ppo1=0,ppo2=0,ppo_mx=-1000000;
        for(long j=i;j<=n;j++){
            if(a[j]>=ppo_mx){
                ppo_mx=a[j];
            }
            ppo1++;
            ppo2+=a[j];
            if(ppo1>=3){
                if(ppo2>ppo_mx*2){
                    ans++;
                }else{
                    break;
                }
            }
        }
    }cout<<ans;
    return 0;
}
