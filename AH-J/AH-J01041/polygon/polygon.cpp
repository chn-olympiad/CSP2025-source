#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int n,a[5005],cnt,ans;
bool vis[5005];
bool Judge(){
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
            return false;
    return true;
}
void dfs(int idx){
    if(idx==n+1){
        if(cnt<=2)
            return ;
        int sum=0,pos=0;
        for(int i=n;i>=1;i--){
            if(vis[i]){
                pos=a[i];
                break;
            }
        }
        for(int i=1;i<=n;i++)
            if(vis[i])
                sum+=a[i];
        if(sum>pos*2)
            ans++;
        return ;
    }
    vis[idx]=true;
    cnt++;
    dfs(idx+1);
    vis[idx]=false;
    cnt--;
    dfs(idx+1);
    return ;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(Judge()){
        int ans=1;
        for(int i=1;i<=n;i++)
            ans=(ans*2)%998244353;
        cout<<(998244353+ans-n*(n-1)/2-n-1)%998244353;
        return 0;
    }
    dfs(1);
    cout<<ans%998244353;
    return 0;
}
