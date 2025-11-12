#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N] , f[N][4] , b[N], c[N] , n , ans , total;
bool vis[N];
bool cmp(ll x , ll y){
return x>y;}
void dfs_2(ll x , ll cnt , ll jj){
    if(cnt>=n/2){
    ll cc = 0;
    for(int i = 1 ; i<=n ; i++)
        if(!vis[i])
            cc+=c[i];
    ans = max(ans,jj+cc);
    return;}
    if(cnt==n||total==n/2)
        return;
    for(int i = 1 ; i<=n ; i++){
        if(!vis[i]){
            vis[i] = 1;
            total++;
            dfs_2(i,cnt+1,jj+b[i]);
            total--;
            vis[i] = 0;
        }
    }
}
void dfs_1(ll x , ll cnt , ll jj){
    dfs_2(1,cnt,jj);
    if(cnt==n/2)
        return;
    for(int i = x ; i<=n ; i++){
        if(!vis[i]){
            vis[i] = 1;

            dfs_1(i,cnt+1,jj+a[i]);
            vis[i] = 0;
        }
    }
}
void dfs(ll x , ll cnt , ll jj){
    if(cnt==n/2){
    ll cc = 0;
    for(int i = 1 ; i<=n ; i++){
        if(!vis[i])
            cc+=b[i];
       // else cout<<i<<' ';
    }
    //cout<<endl;
    ans = max(ans,jj+cc);
    return;}
    for(int i = x+1 ; i<=n ; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs_1(i,cnt+1,jj+a[i]);
            vis[i] = 0;
        }
    }
}
//I'm stupid
void solve(){
    memset(vis,0,sizeof vis);
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    ll sum_a , sum_b,  sum_c;
    sum_a = sum_b = sum_c = 0;
    cin>>n;
    bool flag_1 = 1 , flag_2 = 1;
    for(int i = 1 ; i<=n ; i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]) flag_1 = 0;
        if(c[i]) flag_2 = 0;
    }
    ans = 0;
    if(flag_1){
        sort(a+1,a+n+1,cmp);
        for(int i = 1 ; i<=n/2 ; i++)
            ans+=a[i];
        cout<<ans<<'\n';
    }
    else if(flag_2){
         memset(vis,0,sizeof vis);
         for(int i = 1 ; i<=n ; i++)
            dfs(i,1,0);
        cout<<ans<<'\n';
    }
    else{
        total = 0 , ans = 0;
        memset(vis,0,sizeof vis);
        dfs_1(1,0,0);
        cout<<ans<<'\n';
    }
    /*
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    sort(c+1,c+n+1,cmp);
    for(int i = 0 , j = 0 , k = 0; cnt<n ; cnt++){
        ll maxn = -INT_MAX;
        maxn = max(a[i+1],max(b[j+1],c[k+1]));
        ans+=maxn;
        if(maxn==a[i+1]) i++;
        else if(maxn==b[j+1]) j++;
        else k++;
        if(i==n/2) memset(a,-1,sizeof a);
        if(j==n/2) memset(b,-1,sizeof b);
        if(k==n/2) memset(c,-1,sizeof c);
        //cout<<i<<' '<<j<<' '<<k<<' '<<maxn<<endl;
    }
    cout<<ans<<'\n';
    */
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
