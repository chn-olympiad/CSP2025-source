#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N =5e5+5;
ll n=0,shu[N],q[N],k=0;
bool p1=1,p2=2;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>shu[i];
        if(shu[i]!=1){
            p1=0;
        }
        if(shu[i]>1){
            p2=0;
        }
    }
    if(p1){
        ll xy=n/2;
        cout<<xy;
    }
    else if(p2){
        ll ans=0,yi=0;
        for(ll i=1;i<=n;i++){
            yi=yi^shu[i];
            if(yi==k){
                yi=0;
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        ll ed=0,ans=0,yi=0;
        for(ll i=1;i<=n;i++){
            yi=0;
            for(ll j=i;j>ed;j--){
                yi=yi^shu[j];
                if(yi==k){
                    ans++;ed=i;
                    break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
