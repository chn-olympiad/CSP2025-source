#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=510;
int n,m;
int ans;
string s;
int a[N];
int check(int now[]){
    int cnt=0,ban=0;
    for(int i=1;i<=n;i++){
        if(now[i]<=ban || s[i-1]=='0'){
            ban++;
            continue;
        }
        cnt++;
        if(cnt==m) return 1;
    }
    return 0;
}
void dfs(int now[],bool st[],int cnt){
    if(cnt==n){
        ans+=check(now);
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            now[cnt+1]=a[i];
            dfs(now,st,cnt+1);
            st[i]=false;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool tmp[N]={0};
    int ttmp[N]={0};
    dfs(ttmp,tmp,0);
    cout<<ans;
    return 0;
}
