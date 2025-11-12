#include<bits/stdc++.h>
using namespace std;
#define ll long long
void IOS(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
bool use[5090];ll a[5090],ans=0,n;
const ll N=998244353;
bool check(){
    ll mx=INT_MIN,sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(use[i]){
            cnt+=1;
            sum+=a[i];
            mx=max(mx,a[i]);
        }
    }
    if(cnt<3) return 0;
    if(sum>2*mx) return 1;
    return 0;
}
void dfs(ll step){
    if(step==n+1){
        if(check()){
            ans=(ans+1)%(ll)(N);
        }
        return ;
    }
    use[step]=0;
    dfs(step+1);

    use[step]=1;
    dfs(step+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    IOS();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
}
