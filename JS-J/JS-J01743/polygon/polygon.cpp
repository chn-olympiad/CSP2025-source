#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=0;
int n;
void dfs(int dep,long long maxx,long long sum){
    if(dep==n+1) {
        if(sum>maxx*2) ans++;
        ans%=998244353;
        return ;
    }
    dfs(dep+1,maxx,sum);
    dfs(dep+1,max(maxx,a[dep]),sum+a[dep]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool ok=1;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=1){
            ok=0;
        }
    }
    if(ok){
        long long s=0;
        for(int i=1;i<=n-2;i++){
            long long x=1;
            for(int j=n;j>=i;j--) x*=j,x%=998244353;
            s+=x;
            s%=998244353;
        }
        cout<<s;
    }else{
        dfs(1,0,0);
        cout<<ans;
    }
    return 0;
}
//20
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
