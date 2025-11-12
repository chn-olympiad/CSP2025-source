#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define ll long long
void read(ll &x){
    char c = getchar_unlocked();
    bool f = 0;
    x = 0;
    while(c<'0'||c>'9'){
        if(c=='-')f = -f;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x = x*10+(c-'0');
        c=getchar_unlocked();
    }
    if(f)x = -x;
}
struct S{
    ll a,b,c,id;
};
ll all_ans = 0;
ll n;
void dfs(int x,ll ans,int a,int b,int c,vector<S>&h){
    if(x == n){
        all_ans = max(all_ans,ans);
        return ;
    }
    if(a+1<=n/2)dfs(x+1,ans+h[x].a,a+1,b,c,h);
    if(b+1<=n/2)dfs(x+1,ans+h[x].b,a,b+1,c,h);
    if(c+1<=n/2)dfs(x+1,ans+h[x].c,a,b,c+1,h);
}
void solve(){
    read(n);
    vector<S>h(n);
    vector<bool>vis(n,1);
    for(int i=0;i<n;i++){
        read(h[i].a);
        read(h[i].b);
        read(h[i].c);
        h[i].id = i;
    }
    if(n<=10){
        all_ans = 0;
        dfs(0,0,0,0,0,h);
        cout<<all_ans<<endl;
        return ;
    }
    ll ans = 0;
    sort(h.begin(),h.end(),[&](S s1,S s2){return s1.a>s2.a;});

    for(int i=0,j=0;i<n;i++){
        if(h[i].a>h[i].b && h[i].a > h[i].c){
            ans += h[i].a;
            vis[h[i].id] = 0;
            j++;
            if(j == n/2)break;
        }
    }
    sort(h.begin(),h.end(),[&](S s1,S s2){return s1.b>s2.b;});

    for(int i=0,j=0;i<n;i++){
        if(!vis[h[i].id])continue;
        if(h[i].b > h[i].c){
            ans += h[i].b;
            vis[h[i].id] = 0;
            j++;
            if(j == n/2)break;
        }
    }sort(h.begin(),h.end(),[&](S s1,S s2){return s1.b>s2.b;});

    for(int i=0,j=0;i<n;i++){
        if(!vis[h[i].id])continue;
        ans += h[i].c;
        vis[h[i].id] = 0;
    }

    cout<<ans<<endl;
}
int main(){
    #ifdef LOCAL
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif // LOCAL
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
