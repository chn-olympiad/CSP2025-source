#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
string nd;
vector<ll> nx;
vector<bool> flag;
ll n,m,f[1000],cnt;
ll dfs(ll d,ll s,ll c){
    ll sum=0;
    if(c==m)
        return max(1LL,f[n-d+1]);
    for(int i=1;i<=n;i++){
        if(flag[i]==true)
            continue;
        flag[i]=true;
        if(s>=nx[i])
            sum+=dfs(d+1,s+1,c)%mod,sum%=mod;
        else{
            if(nd[d]=='0')
                sum+=dfs(d+1,s+1,c)%mod,sum%=mod;
            else if(nd[d]=='1')
                sum+=dfs(d+1,s,c+1)%mod,sum%=mod;
        }
        flag[i]=false;
    }
    return sum%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    f[0]=f[1]=1;
    for(int i=2;i<=800;i++)
        f[i]=f[i-1]*(i)%mod,f[i]%=mod;
    cin>>n>>m>>nd,nd=" "+nd,nx=vector<ll>(n+10,0),flag=vector<bool>(n+10,false);
    for(int i=1;i<=n;i++)
        cin>>nx[i];
    cout<<dfs(1,0,0)%mod;
    return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/