#include <bits/stdc++.h>
using namespace std;
const long long N=5e3+5;
long long n,a[N],vis[N],cnt;
vector<long long> v;
void try10(){
    long long sum=a[1]+a[2]+a[3],maxn=max(a[1],max(a[2],a[3]));
    if(sum>2*maxn) cout<<1;
    else cout<<0;
}
void dfs(long long cur,long long x,long long sum){
    memset(vis,0,sizeof vis);
    if(cur>n){
        if(x>2*sum){
            cnt++;
            cnt%=998244353;
        }
        return ;
    }
    dfs(cur+1,x,sum);
    if(!vis[cur]){
        vis[cur]=1;
        v.push_back(a[cur]);
        dfs(cur+1,x+a[cur],max(sum,a[cur]));
        vis[cur]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2) cout<<0;
    else if(n==3){
        try10();
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<cnt%998244353;
    return 0;
}
