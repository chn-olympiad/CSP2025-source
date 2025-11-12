#include<bits/stdc++.h>
using namespace std;

int ans=0,n,a[10010],t[10010];

void dfs(int dep,int x) {
    if (dep>3) {
        int maxn=-1,cnt=0;
        for (int i=1;i<dep;i++) maxn=max(maxn,t[i]),cnt+=t[i];
        if (cnt>maxn*2)ans=(ans+1)%998244353;
    }
    if (dep==n+1) return;
    for (int i=x;i<=n;i++) {
        t[dep]=a[i];
        dfs(dep+1,i+1);
    }
}

int main () {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
