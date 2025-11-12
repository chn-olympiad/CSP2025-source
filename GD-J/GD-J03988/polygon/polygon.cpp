#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5010];
int maxn=-1;
long long ans=0;
int t[5010];
bool v[5010]={0};

void dfs(int x,int deep,int sx){
    if(deep>x){
        maxn=-1;
        long long tot=0;
        for(int i=1;i<=x;i++){
            maxn=max(maxn,a[t[i]]);
            tot+=a[t[i]];
            maxn%=mod;
            tot%=mod;
        }
        if(tot>2*maxn)ans++;
        ans%=mod;
        return;
    }
    for(int i=sx;i<=n;i++){
        t[deep]=i;
        v[i]=1;
        dfs(x,deep+1,i+1);
        v[i]=0;
        t[deep]=0;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=3;i<=n;i++){
        dfs(i,1,1);
    }
    cout<<ans;
    return 0;
}
