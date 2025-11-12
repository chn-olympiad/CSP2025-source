#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],q[5005];
long long cnt2=0;
int n;
void dfs(int dep,int cnt,int sum,int maxx,bool flag){
    if(dep>n+1) return;
    if(cnt>=3 && flag==0){
        if(sum>2*maxx) cnt2++;
        cnt2%=mod;
    }
    dfs(dep+1,cnt,sum,maxx,1);
    int k=max(maxx,a[dep]);
    dfs(dep+1,cnt+1,sum+a[dep],k,0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0,0,0);
    cout<<cnt2%mod;
    return 0;
}
