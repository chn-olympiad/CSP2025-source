#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod=998244353;
struct node{
    ll sum,cnt;
};
int n;
ll a[5005];
ll ans=0;
int m=0;
void dfs(ll cnt,ll sum,ll i,bool flag){
    if(i==n+1){
        if(cnt>=3&&flag){
            ans++;
            ans%=mod;
        }
        return;
    }
    dfs(cnt,sum,i+1,flag);
    if(cnt>=2){
        if(sum>a[i]){
            dfs(cnt+1,sum+a[i],i+1,1);
        }
        else{
            dfs(cnt+1,sum+a[i],i+1,0);
        }
    }
    else{
        dfs(cnt+1,sum+a[i],i+1,0);
    }
    return;
}
void bfs2(){
    queue<node> q;
    q.push({0,0});
    while(!q.empty()){
        node t=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(t.sum>a[i]){
                if(t.sum+a[i]>a[n]){

                }
                else{
                    q.push({t.cnt+1,t.sum+a[i]});
                }
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    m=a[n];
    dfs(0,0,1,0);
    cout<<ans;
    return 0;
}
