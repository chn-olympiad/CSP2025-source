#include <bits/stdc++.h>
#define int long long
#define N 5005
#define mod 998244353
using namespace std;
int a[N];
int ans,n,sum;
void dfs(int i,int sum,int ma){
    if(i==(n+1)){
        if(sum>(ma*2))
            ans++;
        return;
    }
    dfs(i+1,sum+a[i],max(ma,a[i]));
    dfs(i+1,sum,ma);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]%mod;
        sum+=a[i];
    }
    if(sum!=n)
        dfs(1,0,0);
    else
        ans=n*(n-1)/2;
    cout<<ans%mod;
    return 0;
}
