#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
string s;
int n,m,pa[N],cnt,ans;
int mul[N],pre[N];
void init(int x){
    mul[1]=1;
    for(int i=2;i<=x;i++) mul[i]=1ll*mul[i-1]*i%mod;
}
int li[N],vis[N];
bool check(){
    for(int i=1;i<=n;i++){
        if(pa[li[i]]<=pre[i]) return 0;
    }
    return 1;
}
void dfs(int x,int k){
    if(x==k){if(check()) ans=(ans+1)%mod; return;}
    for(int i=x+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1; li[x+1]=i;
            dfs(x+1,k);
            vis[i]=0; li[x+1]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s; int len=s.size();
    for(int i=1;i<=n;i++) cin>>pa[i];
    for(int i=0;i<len;i++){
        if(s[i]=='0') pre[i]=pre[i-1]+1;
        else pre[i]=0,cnt++;
    }
    if(cnt==len){cout<<mul[n]%mod; return 0;}
    if(n<=10){
        dfs(0,n); cout<<ans%mod;
    }
	return 0;
}
