#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6 + 100 ;
int n,k,a[N],x[N],cnt[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    ll l=0,r=0;
    cnt[0]++;
    ll ans=0;
    while(r<n){
        r++;
        if(k!=0) cnt[x[r]]++;
        if(cnt[x[r]^k]!=0){
            while(l<r){
                cnt[x[l]]--;
                l++;
            }
            ans++;
        }
        if(k==0) cnt[x[r]]++;
    }
    cout<<ans;
    return 0;
}
