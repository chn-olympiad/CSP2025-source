#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=998244353;
ll n,a[5010],oc[5010],sol;
bool xz1=1;
ll power(ll x,ll y){
    if(y==0) return 1;
    ll ans=1;
    while(y){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll solve(ll rem,ll mx){
    if(rem<=1) return 0;
    ll ans=0;
    for(int i=1;i<=mx;i++){
        if(oc[i]){
            for(int j=1;j<=oc[i];j++){
                ans+=solve(rem-i*j,mx)%mod;
            }
        }
    }
    return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        oc[a[i]]++;
        if(a[i]>1) xz1=0;
    }
    if(xz1){
        cout<<power(2,n)-(n*n+n+2)/2;//all possible-2's-1's-0's simplified
        return 0;
    }
    if(n<=22){
        ll ans=0;
        for(int mask=1;mask<(1ll<<n);mask++){
            vector<ll> tmp;
            ll sum=0;
            for(int i=1;i<=n;i++){
                if(mask&(1ll<<(i-1))){
                    tmp.push_back(a[i]),sum+=a[i];
                    //cout<<i<<' ';//delete
                }
            }
            //cout<<'\n';//delete
            if(tmp.size()<3) continue;
            ll mx=*max_element(tmp.begin(),tmp.end());
            if(sum>mx*2){
                ans++;
                //for(auto i:tmp) cout<<i<<' ';//delete
                //cout<<'\n';//delete
            }
        }
        cout<<ans%mod;
        return 0;
    }
    for(int i=5000;i>=1;i--){
        if(oc[i]!=0){
        ll tgt=i*2,sum=0;
        for(int j=1;j<=i;j++){
            sum+=j*oc[j];
        }
        ll rem=sum-tgt;
        if(rem<0){
            cout<<sol;
            return 0;
        }
        //this sequence contains rem more,try to remove a little
        sol+=solve(rem,i);
        //After testing it is extremely easy to TLE,but can't think of a better way
        }
    }
    cout<<sol;
	return 0;
}
