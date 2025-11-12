#include <bits/stdc++.h>
using namespace std;

long long a[5005];

long long solve(long long cnt,long long p,long long amax){
    long long num=-1;
    long long tot=cnt;
    long long ans=1;
    for(int t=p;t>0;t--){
        if(cnt-a[t]>=amax){
            num=t;
            break;
        }
        else{
            tot-=a[t];
        }
    }
    for(int t=num;t>0;t--){
        ans+=solve(tot-a[t],t-1,amax);
        ans%=998244353;
    }
    ans%=998244353;
    return ans;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long tot=0;
    for(int t=1;t<=n;t++){
        cin>>a[t];
        tot+=a[t];
    }
    sort(a,a+n);
    tot-=a[n];
    long long ans=0;
    for(int t=n;t>0 && tot>=a[t]+1;t--){
        ans+=solve(tot,t-1,a[t]+1);
        ans%=998244353;
        tot-=a[t-1];
    }
    cout<<ans<<endl;
    return 0;
}
