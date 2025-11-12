#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5e4;
ll f[N],n,k,sum=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
    }
    //ll s[N];
    //s[1]=f[1];
    /*for(int i=2;i<=n;i++){
        s[i]=s[i-1]^f[i];
    }*/
    for(ll l1=1;l1<=n;l1++){
        for(ll r1=l1;r1<=n;r1++){
            if(r1-l1==n-1){
                continue;
            }
            ll cnt=f[l1];
            for(ll i=l1+1;i<=r1;i++){
                cnt^=f[i];
            }if(cnt==k){
                sum=max(sum,1ll);
                for(ll l2=r1+1;l2<=n;l2++){
                    for(ll r2=l2+1;r2<=n;r2++){
                        if(r2-l2==n-1){
                            continue;
                        }
                        ll cnt2=f[l2];
                        for(ll i=l2+1;i<=r2;i++){
                            cnt2^=f[i];
                        }if(cnt2==k){
                            sum=max(sum,2ll);
                        }
                    }
                }
            }
        }
    }cout<<sum;
    return 0;
}
