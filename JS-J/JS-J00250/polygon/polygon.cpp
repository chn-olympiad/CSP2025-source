#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans;
const int MOD=998244353;
void dfs(long long d,long long m,long long z,long long s){
    if(d<n)
        dfs(d+1,m,z,s);
    m=max(m,a[d]);
    if(2*m<z+a[d]&&s>1){
        ans++;
        ans=ans%MOD;
    }
    if(d<n)
        dfs(d+1,m,z+a[d],s+1);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}


