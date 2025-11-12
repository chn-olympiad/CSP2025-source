#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int n;
int think[N][3],a[N];
bool vis[N];
int ans  = 0;
int cont = 0;
void dfs(int idx,int sum){
    cont++;
    if(idx==n+1){
        //cout<<sum<<endl;
        ans = max(ans,sum);
        return ;
    }
    for(int i=1;i<=n/2*3;++i){
        if(vis[i]==false){
            vis[i] = true;
            //for(int i=1;i<=n/2*3;++i){cout<<vis[i]<<" ";}
            //<<endl;
            dfs(idx+1,sum+think[idx][a[i]]);
            vis[i] = false;
        }
    }
}
void sovle(){
    memset(a,0,sizeof(a));
    memset(think,0,sizeof(think));
    memset(vis,0,sizeof(vis));
    ans = 0;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j){
            cin>>think[i][j];
        }
    }
    int k =n/2;
    int cnt = 0;
    for(int i=1;i<=k;++i){
        a[++cnt] = 1;
    }
    for(int i=1;i<=k;++i){
        a[++cnt] = 2;
    }
    for(int i=1;i<=k;++i){
        a[++cnt] = 3;
    }
    //for(int i=1;i<=n/2*3;++i) cout<<a[i]<<" ";
    //cout<<endl;
    dfs(1,0);
    cout<<ans<<" "<<cont;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    //cin>>N;
    while(N--) sovle();
    return 0;
}

