#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
ll ans;
bool vis[N];
vector<int> v;

bool check(){
    int fq=0;
    int lq=0;
    for(int i=1;i<=n;i++){
        if(fq>=c[v[i-1]]||s[i]=='0') fq++;
        else lq++;
    }
    return lq>=m;
}

void dfs(int k){
    if(k==n){
        if(check()) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        v.push_back(i);
        dfs(k+1);
        v.pop_back();
        vis[i]=false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    dfs(0);
    cout<<ans;

    return 0;
}

