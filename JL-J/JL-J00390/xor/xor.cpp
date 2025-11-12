#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ans,cnt,cnt0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt++;
        if(a[i]==0) cnt0++;
    }
    if(cnt==n){
        cout<<n/2<<'\n';
        return 0;
    }
    if(cnt+cnt0==n){
        if(k==0) cout<<cnt0<<'\n';
        else cout<<cnt<<'\n';
        return 0;
    }
    ll num=a[1];
    for(int i=2;i<=n;i++){
        if(num==k){
            ans++;
            num=a[i];
        }else{
            num^=a[i];
        }
    }
    if(num==k) ans++;
    cout<<ans<<'\n';
    return 0;
}
//这里用的贪心策略不对，代码很轻松就能被hack掉，但是蒟蒻想不出来了QAQ……
