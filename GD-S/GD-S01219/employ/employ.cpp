#include<iostream>
#define ll long long
using std::cin;
using std::cout;
const ll N=1e3+10,p=998244353;
char s[N],bz[N];
ll a[N],ans;
void dfs(ll x,ll n,ll m,ll give_up){
    if(x>n){
        ans+=give_up<=n-m;
        return;
    }
    for(ll i=1;i<=n;++i){
        if(!bz[i]){
            bz[i]=1;
            give_up+=a[i]<=give_up||s[x]=='0';
            dfs(x+1,n,m,give_up);
            give_up-=a[i]<=give_up||s[x]=='0';
            bz[i]=0;
        }   
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    ll i;
    cin>>n>>m>>(s+1);
    if(n<=15){
        for(i=1;i<=n;++i)
            cin>>a[i];
        dfs(1,n,m,0);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
