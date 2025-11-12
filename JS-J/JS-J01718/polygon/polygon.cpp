#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=998244353;
int n;
class sol1{
public:
    bool used[25];
    int a[25];
    ll ans=0;
    bool check(){
        int mx=0,sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(used[i]){
                mx=max(mx,a[i]);
                sum+=a[i];
                cnt++;
            }
        }
        if(cnt>=3&&sum>2*mx) return true;
        return false;
    }
    void sear(int x){
        if(x==n+1){
            if(check()){
                ans++;
            }
            return;
        }
        sear(x+1);
        used[x]=true;
        sear(x+1);
        used[x]=false;
        return;
    }
    void solve(){
        memset(used,0,sizeof used);
        for(int i=1;i<=n;i++) cin>>a[i];
        sear(1);
        cout<<ans<<'\n';
    }
};
class sol2{
public:
    ll qpow(ll a,ll b=M-2){
        ll r=1;
        while(b){
            if(b&1) r=(r*a)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return r;
    }
    void solve(){
        ll ans=qpow(2ll,(ll)n);
        ans=ans-n-(n*(n-1)/2)-1;
        ans=(ans+M)%M;
        cout<<ans<<'\n';
    }
};

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n<=20){
        sol1 s;
        s.solve();
        return 0;
    }
    vector<int> a(n+1);
    bool sp1=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) sp1=false;
    }
    if(sp1){
        sol2 s;
        s.solve();
        return 0;
    }
}