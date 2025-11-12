#include <bits/stdc++.h>
using namespace std;

const int N=5e3+7,mod=998244353;
typedef long long ll;

ll a[N],n,ans;
bool f=1;
bool vis[N];
ll j[N+10];

void dfs(ll dep,ll mx,ll sum){
    if(dep==n+1){
        if(sum>2*mx)
            ans++;
        ans%=mod;
        return;
    }
    //yes
    dfs(dep+1,max(mx,a[dep]),sum+a[dep]);
    //no
    dfs(dep+1,mx,sum);
}

ll jc(ll x){
    if(j[x]) return j[x];
    ll sum=1;
    for(int i=1;i<=x;i++){
        sum*=i;
        sum%=mod;
    }
    j[x]=sum;
    return sum;
}

ll C(ll nn,ll mm){
    if(nn==mm) return 1;
    ll now=(jc(nn))/(jc(mm)*jc(nn-mm));
    now%=mod;
    return now;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f){
        ll res=0;
        if(n==1||n==2) cout<<0<<endl;
        else{
            for(int i=3;i<=n;i++){
                res+=C(n,i);
                res%=mod;
            }
            cout<<res%mod<<endl;
        }
        return 0;
    }
    dfs(1,0,0);
    cout<<ans%mod;
    return 0;
}
