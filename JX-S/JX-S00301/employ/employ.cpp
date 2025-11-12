#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define pow po_w
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9'){ if (ch=='-')f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll po_w(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll gcd(ll x,ll y){
    if (y==0)
        return x;
    return gcd(y,x%y);
}
int n,m,a[505],c[505];
string s;
const ll mod=998244353;
bool vis[505];
bool check(){
    int cnt=0,sum=0;
    for (int i=1;i<=n;i++){
        if (cnt>=a[c[i]]){
            cnt++;
            continue;
        }
        if (s[i-1]=='1')
            sum++;
        else
            cnt++;
    }
    return sum>=m;
}
ll ans;
void dfs(int x){
    if (x==n+1){
        if (check()){
            ans++;
            // for (int i=1;i<=n;i++)
            //     printf("%d ",c[i]);
            // printf("\n");
        }
        return;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            vis[i]=true;
            c[x]=i;
            dfs(x+1);
            vis[i]=false;
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    // bool flot=true;
    // for (int i=0;i<n;i++)
    //     if (s[i]=='0')
    //         flot=false;
    // if (flot){
    //     int cnt=0;
    //     for (int i=1;i<=n;i++)
    //         if (a[i]!=0)
    //             cnt++;
    //     if (cnt<m){
    //         printf("0\n");
    //         return;
    //     }
        
    // }
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}