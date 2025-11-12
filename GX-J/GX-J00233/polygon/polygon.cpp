#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5005],cnt,maxa;
void dfs(int dep,int sum,int cs){
    if(dep>n){
        cnt%=mod;
        if(sum>2*maxa&&cs>2)cnt++;
        return ;
    }
    dfs(dep+1,sum,cs);
    int bf=maxa;
    maxa=max(maxa,a[dep]);
    dfs(dep+1,sum+a[dep],cs+1);
    maxa=bf;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout <<cnt;
    return 0;
}
