#include<bits/stdc++.h>
using namespace std;
long long ans,a[5005],n;
bool f[5005];
void dfs(long long sum,long long choose,long long maxn){
    if(choose>n) return;
    if(sum+a[choose]>max(maxn,a[choose])*2) ++ans;
    dfs(sum+a[choose],choose+1,max(a[choose],maxn));
    dfs(sum,choose+1,maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    dfs(0,0,0);
    ans/=2;
    ans=ans%998;
    ans=ans%244;
    ans=ans%353;
    cout<<ans;
    return 0;
}
