#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+10;
struct edge{
    ll on,tw,th,bh;
}ar[N];
ll n,T,dp[3][N],ans=0;
ll f[N];
void dfs(ll e,ll r,ll s,ll cnt,ll op){
    if(e>n/2||r>n/2||s>n/2)return ;
    if(op>n){
        ans=max(ans,cnt);
        return ;
    }
    dfs(e+1,r,s,cnt+ar[op].on,op+1);
    dfs(e,r,s+1,cnt+ar[op].tw,op+1);
    dfs(e,r+1,s,cnt+ar[op].th,op+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        f(i,1,n)f[i]=0;
        f(i,1,n){
            cin>>ar[i].on>>ar[i].tw>>ar[i].th;
            ar[i].bh=i;
        }
        dfs(0,0,0,0,1);
        cout<<ans<<endl;
    }
    return 0;
}