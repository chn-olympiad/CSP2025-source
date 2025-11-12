#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=998244353;
const int MAXN=510;
typedef long long ll;
string a;
int c[MAXN],n,m;
int p[MAXN];
bool vis[MAXN];
int ans=0;
bool Check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]=='1'&&i-cnt-1>=c[p[i]]){
            cnt++;
        }
    }
    // if(cnt>=m){
    //     for(int i=1;i<=n;i++){
    //         cout<<p[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    return cnt>=m;
}
void Dfs(int x){
    if(x>n){
        ans+=Check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        vis[i]=1;
        p[x]=i;
        Dfs(x+1);
        vis[i]=0;
    }
}
void Baoli(){
    // for(int i=1;i<=n;i++){
    //     p[i]=i;
    // }
    Dfs(1);
    cout<<ans<<endl;
}
void Workm1(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(c[i]!=0);
    }
    ll ans=cnt;
    for(int i=1;i<n;i++){
        ans=ans*i%MOD;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==1){
        Workm1();
    }
    else{
        Baoli();
    }
    return 0;
}