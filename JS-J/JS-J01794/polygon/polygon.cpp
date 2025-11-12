#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,MOD=998244353;

int n,a[N];
long long ans;
bool vis[N];

void dfs(int sum,int c,int m,int j){
    if(c>=3&&sum>2*m){
        ans++;
        ans%=MOD;
    }
    for(int i=j;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(sum+a[i],c+1,max(m,a[i]),i);
            vis[i]=0;
        }
    }
    return;
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dfs(0,0,0,1);

    cout<<ans;

    return 0;
}
