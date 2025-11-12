#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
ll a[N]={},b[N]={};
ll n,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        scanf(%lld,&a[i]);
    }
    ll cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            cnt=0;
            for(int g=i;g<j;++g){
                cnt+=a[i]^a[i+1];
            }
            if(i==j)cnt=a[i];
            if(cnt==k){
                ans++;
                i=j;
            }else if(cnt>k){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
