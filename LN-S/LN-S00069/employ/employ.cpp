#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define ll long long
int n,m,a[110],e,t[110];
ll ans=1;
string s;
bitset<110> q;
bool pd(){
    int c=0,ret=0;
    for(int i=1;i<=n;i++){
        if(c>=t[i]){
            c++;
            continue;
        }
        if(s[i-1]=='1')ret++;
        else c++;
    }
    return ret>=m;
}
void dfs(int step){
    if(step==n+1){
        if(pd())ans=(ans+1)%mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(q[i])continue;
        q[i]=1;
        t[step]=a[i];
        dfs(step+1);
        q[i]=0;
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    bool b=1;
    for(int i=0;i<s.size();i++)if(s[i]=='0')b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0)e++;
    }
    if(b&&e>=m){
        for(int i=2;i<=n;i++)ans=ans*i%mod;
        printf("%lld",ans);
        return 0;
    }
    dfs(1);
    cout<<ans-1;
    return 0;
}
