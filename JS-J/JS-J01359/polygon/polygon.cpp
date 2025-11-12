#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,mod=998244353;
ll n,arr[N],ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<pow(2,n+1);i++){
        ll sum=0,mx=-1,cnt=0;
        for(ll j=1;j<=n;j++){
            if((i>>j)&1){
                cnt++;
                sum=sum+arr[j];
                mx=max(mx,arr[j]);
            }
        }
        //cout<<cnt<<" "<<sum<<" "<<mx<<'\n';
        if(cnt>=3&&sum>2*mx)ans=ans+1;
    }
    cout<<ans/2%mod;
    return 0;
}
