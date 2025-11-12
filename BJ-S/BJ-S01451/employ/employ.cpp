#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
const int maxn=507;

int n,m;
int c[maxn];
bool vis[maxn];
string s;

void solveA(){
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(c[i] == 0)
            cnt++;
    if(n-cnt < m){
        cout<<0<<endl;
        return;
    }
    long long res=1;
    for(long long i=1;i<=n;i++){
        res *= i;
        res %= MOD;
    }
    cout<<res<<endl;
    return;
}

int p[maxn];
bool check(){
    int cnt=0,leave=0;
    for(int i=1;i<=n;i++){
        if(c[p[i]] <= leave){
            leave++;
            continue;
        }
        if(s[i] == '1'){
            cnt++;
            if(cnt >= m)
                return true;
        }
        else{
            leave++;
        }
    }
    if(cnt >= m)
        return true;
    else
        return false;
}

long long ans=0;
void dfs(int ind){
    if(ind > n){
        if(check()){
            ans++, ans%=MOD;
            /*
            for(int i=1;i<=n;i++)
                cout<<p[i]<<" ";
            cout<<endl;
            */
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        p[ind] = i;
        vis[i] = true;
        dfs(ind+1);
        vis[i] = false;
    }
    return;
}

void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(c[i] == 0)
            cnt++;
    if(n-cnt < m){
        cout<<0<<endl;
        return;
    }
    dfs(1);
    cout<<ans<<endl;
    return;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s = "0"+s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    bool flagA=true;
    for(int i=1;i<=n;i++){
        if(s[i] != '1'){
            flagA = false;
            break;
        }
    }
    if(flagA)
        solveA();
    else
        solve();
    return 0;
}
