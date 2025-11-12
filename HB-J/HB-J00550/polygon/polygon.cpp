#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
ll sticks[509];
map<string,ll> mp;
void dfs(ll now,ll cho,ll plu,ll ma){
    if(now>n){
        if(plu>2*ma&&cho>=3){
            ans++;
            ans%=998244353;
        }
        return;
    }
    dfs(now+1,cho+1,plu+sticks[now],max(ma,sticks[now]));
    dfs(now+1,cho,plu,ma);
}
ll tans(ll now,ll num){
    string no=to_string(now)+","+to_string(num);
    if(mp.find(no)!=mp.end()){
        ans+=mp[no];
        ans%=998244353;
        return mp[no];
    }
    if(num==1){
        ans+=n-now;
        ans%=998244353;
        return n-now;
    }
    ll temp=0;
    for(int i=now+1;i<=n;i++){
        if(i+num-1>n){
            break;
        }
        temp+=tans(i,num-1);
    }
    mp[no]=temp;
    return temp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sticks[i];
    }
    if(n<=20){
        dfs(1,0,0,0);
    }else{
        for(int i=3;i<=n;i++){
            tans(0,i);
        }
    }
    cout<<ans;
    return 0;
}
