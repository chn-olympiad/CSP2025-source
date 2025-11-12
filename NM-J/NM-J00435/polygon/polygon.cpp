#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long ll;
bool can(ll num,ll sum,ll maxn){
    if(num>=3&&sum>maxn*2) return 1;
    else return 0;
}
ll maxn;
ll n,a[5005];
ll mem[5005][5005];
ll found;

void dfs(ll num,ll sum,ll cnt){
    if(mem[num][sum]!=-1){
        return;
    }
    if(num>n){
        if(can(num,sum,maxn)) found=cnt%mod;
        return;
    }

    if(sum<=maxn*2) return;

    mem[num][sum]=cnt;

    int nu=num+1,su=sum+a[num];
    maxn=max(a[num],maxn);
    if(can(nu,su,maxn)){
        dfs(nu,su,(cnt+1)%mod);
    }
    dfs(num+1,sum,cnt);

    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    memset(mem,-1,sizeof(mem));
    dfs(0,0,0);
    cout<<found;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
