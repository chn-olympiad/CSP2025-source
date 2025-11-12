#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans;
ll num[1009],pre[1009],book[1009];
vector<ll> book2[1009];
void dfs(ll now,ll num){
    if(now==n){
        ans=max(ans,num);
        return;
    }
    if(book[now]==0){
        book[now]=num;
    }else{
        if(book[now]>=num){
            return;
        }else{
            book[now]=num;
        }
    }
    for(ll i=0;i<book2[now+1].size();i++){
        dfs(book2[now+1][i],num+1);
    }
    dfs(now+1,num);
    ans=max(ans,num);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>num[i];
        if(i==1){
            pre[i]=num[i];
        }else{
            pre[i]=num[i]^pre[i-1];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ll plu=pre[j]^pre[i-1];
            if(plu==k){
                book2[i].push_back(j);
            }
        }
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
