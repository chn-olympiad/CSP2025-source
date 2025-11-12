#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=998244353;
ll n,m,c[N],p[4000000][15],mul,cnt,ans,tmp,v[N],l[N];
string s;
void dfs(ll dep){
    if(dep==n+1){
        mul++;
        for(int i=1;i<=n;i++) p[mul][i]=l[i];
        return;
    }
    for(int i=1;i<=n;i++)
        if(!v[i]){
           v[i]=1;
           l[dep]=i;
           dfs(dep+1);
           v[i]=0;
        }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    for(int i=1;i<=mul;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            tmp=p[i][j];
            if(s[j-1]=='0') cnt++;
            else if(cnt>=c[tmp]) cnt++;
//           cout<<tmp<<' '<<cnt<<'*';
        }
        if(n-cnt>=m) ans++;
//        cout<<'*'<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
