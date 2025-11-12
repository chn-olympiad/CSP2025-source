#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int p[N];
ll ans;
bool st[N];
void dfs(int k){
    if(k==n+1){
        int cnt=0,res=0;
        for(int i=1;i<=n;i++){
            if(c[p[i]]<=cnt){
                cnt++;
            }
            else{
                if(s[i]=='0') cnt++;
                else res++;
            }
        }
        if(res>=m) ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        st[i]=true;
        p[k]=i;
        dfs(k+1);
        st[i]=false;
    }
}
int main(){
    //update file name!!!
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
