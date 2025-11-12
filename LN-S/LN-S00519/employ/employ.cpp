#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,p=998244353;
int n,m,ans,c[N],pre[N],fac[N];
bool vis[N];
string s;

void dfs(int depth,int cur){
    if(depth==n+1){
        if(cur>=m){
            ans=(ans+1)%p;
        }
        return;
    }
    if(cur+n-depth+1<m)return;
    if(cur>=m){
        ans=(ans+fac[n-depth+1])%p;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        int C=cur;
        if(s[depth-1]=='1'&&depth-1-cur<c[i])C++;
        dfs(depth+1,C);
        vis[i]=0;
    }
}

void solve(){
    for(int i=1;i<=n;i++)
        pre[ c[i] ]++;
    for(int i=1;i<=n;i++)
        pre[i]+=pre[i-1];
    int cnt=0,sum=1;
    for(int i=0;i<n;i++){
        if(s[i]=='0')continue;
        cnt++;
        (ans+=fac[n-cnt]*(pre[n]-pre[i])%p*sum%p)%=p;
        sum=sum*(pre[i]-cnt+1)%p;
    }
}

void solve2(){
    bool flag=1;
    for(int i=0;i<n;i++)
        if(s[i]=='0'){
            flag=0;
            break;
        }
    for(int i=1;i<=n;i++)
        if(c[i]==0){
            flag=0;
            break;
        }
    if(flag==0)return;
    ans=1;
    for(int i=2;i<=n;i++)
        ans=ans*i%p;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%p;
    if(m==1)solve();
    else if(m==n)solve2();
    else dfs(1,0);
    cout<<ans;
}
