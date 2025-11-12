#include<bits/stdc++.h>
using namespace std;
long long n,p,a[500005],dp[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>p;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long sum=0;
        bool f=0;
        for(long long k=i;k<=n;k++){
            for(long long j=k;j<=n;j++){
                sum^=a[j];
                if(sum==p){
                    i=j;
                    ans++;
                    f=1;
                    break;
                }
            }
            if(f){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
