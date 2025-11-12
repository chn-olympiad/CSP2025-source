#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[6000],ans=0;
long long sum1[6000];
void dfs(int now,int cnt,long long sum,int maxn){
    if((sum+(sum1[n]-sum1[now-1])<=2*maxn))return;
    if(now>n||cnt==0){
        if((cnt==0)&&(sum>2*maxn)){
            ++ans;
            if(ans>=MOD)ans%=MOD;
        }
        return;
    }
    dfs(now+1,cnt-1,sum+a[now],max(maxn,a[now]));
    dfs(now+1,cnt,sum,maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum1[i]=sum1[i-1]+a[i];
    }
    if(sum1[n]==n){
        cout<<(1+(n-1))*(n-1)/2;
        return 0;
    }
    for(int i=3;i<=n;++i){
        dfs(1,i,0,0);
    }
    cout<<ans;
    return 0;
}
