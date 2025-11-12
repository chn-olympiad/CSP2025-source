#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[6000];
int ans,MOD=998244353;
void dfs(int i,int num,ll cnt,ll maxn){
    if(i==n+1){
        if(num==0){
            if(cnt>2*maxn){
                ans++;
                ans%=MOD;
            }
        }return;
    }
    if(num){
       dfs(i+1,num-1,cnt+a[i],max(maxn,a[i]));
    }dfs(i+1,num,cnt,maxn);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int num=1;num<=n;num++){
        dfs(1,num,0,0);
    }cout<<ans;
    return 0;
}
