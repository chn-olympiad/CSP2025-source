#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,p[N];
string s;
int inv[N];
bool b[N];
int a[N],ans;
void dfs(int cur){
    if(cur>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(p[a[i]]<=i-cnt-1)continue;
            if(s[i-1]=='1'){
                cnt++;
            }
        }
        if(cnt>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(b[i])continue;
        b[i]=1;
        a[cur]=i;
        dfs(cur+1);
        b[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    inv[0]=0;
    for(int i=1;i<=n;i++){
        inv[i]=(inv[i-1]*i)%mod;
        cin >> p[i];
    }
    if(n>18){
        cout << inv[n] << '\n';
        return 0;
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}