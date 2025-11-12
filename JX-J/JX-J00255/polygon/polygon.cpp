#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
int n;
ll a[N],sum[N];
ll  ans;
ll f(int x,int y,ll z){
    ll maxx=-99999999;
    for(int i=x;i<=y;i++){
        maxx=max(a[i],maxx);
    }
    maxx=max(maxx,z);
    return maxx;
}
void dfs(int now,ll sum,ll maxx,int cnt){
    if(now>=n){
        if(cnt>=3&&maxx>sum){
            ans++;
            ans%=998244353;
        }
    }
    if(cnt>=3&&maxx>sum){
        ans++;
        ans%=998244353;
    }
    dfs(now+1,sum+a[now],max(maxx,a[now]),cnt++);
    dfs(now,sum,maxx,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<n-1;i++){
        for(int j=i+2;j<=n;j++){
            for(ll t=1;t<=n;t++){
                if(t>=i&&t<=j)  continue;
                if(sum[j]-sum[i-1]>f(i,j,a[t])){
                    ans++;
                    ans%=998244353;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
