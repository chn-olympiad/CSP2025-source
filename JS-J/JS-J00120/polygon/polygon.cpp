#include<bits/stdc++.h>
using namespace std;
int a[5050],n,maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*maxn)cout<<1;
        else cout<<0;
    }else if(maxn==1){
        long long ans=0;
        ans+=1;
        for(int k=n-1;k>=n/2;k--){
            long long sum=1;
            for(int i=n;i>=n-k+1;i--){
                sum*=i;
                sum%=998244353;
            }
            int x=n-k+1;
            for(int i=2;i<x;i++)sum/=i;
            cout<<k<<' '<<sum<<endl;
            ans+=sum;
            if(n%2||(k!=n/2))ans+=sum;
            ans%=998244353;
            cout<<ans<<endl;
        }
        cout<<ans;
    }
    return 0;
}
