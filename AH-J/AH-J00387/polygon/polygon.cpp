#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans;
int n,a[5005];
bool sel[5005];
inline bool check(int e){
     int m=0,maxn=INT_MIN;
     long long tot=0;
     for(int i=1;i<=e;i++){
        if(sel[i]){
            m++;
            maxn=max(maxn,a[i]);
            tot+=a[i];
        }
     }
     if(m<3||tot<=1LL*maxn*2){
        return false;
     }
     return true;
}
void dfs(int now,int m){
    if(now>n&&m!=0) return;
    if(m==0){
        if(check((now>=n?n:now))){
            ans=(ans+1)%MOD;
        }
        return;
    }
    sel[now]=true;
    dfs(now+1,m-1);
    sel[now]=false;
    dfs(now+1,m);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(1,i);
    }
    cout<<ans;
    return 0;
}
