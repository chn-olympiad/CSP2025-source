#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans;
int n,a[5005],sum,maxn;
int f(long long x){
    int cnt=0;
    while(x){
        if(x&1==1) cnt++;
        x>>=1;
    }
    return cnt;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<(1<<n);i++){
        if(f(i)<3) continue;
        sum=0,maxn=0;
        for(long long j=0;j<n;j++){
            if(((1<<j)&i)==1){
                sum+=a[j+1];
                maxn=max(a[j+1],maxn);
            }
        }
        if((sum-maxn)>maxn){
            ans=(ans+1)%mod;
        }
    }
    cout<<ans;
}
