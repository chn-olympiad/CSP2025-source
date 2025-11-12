#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N=510;
const LL mod=998244353;

int n,m,c[N];
string s;

LL Ans;
bool used[15];

void dfs(int now,int cnt){
    if(now==n+1){
        if(cnt>=m) Ans++;
        return;
    }
    for(int i=1;i<=n;++i) if(!used[i]){
        used[i]=1;
        int fail=now-1-cnt;
        dfs(now+1,cnt+(fail<c[i] && s[now]=='1'));
        used[i]=0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s; s="#"+s;
    for(int i=1;i<=n;++i) cin>>c[i];
    if(n<=10){
        dfs(1,0);
        cout<<Ans<<endl;
        return 0;
    }
    else if(m==n){
        int flag=1;
        for(int i=1;i<=n;++i) if(s[i]=='0') flag=0;
        for(int i=1;i<=n;++i) if(!c[i]) flag=0;
        if(!flag) cout<<0<<endl;
        else{
            LL Ans=1;
            for(int i=1;i<=n;++i) Ans=Ans*i%mod;
            cout<<Ans<<endl;
        }
        return 0;
    }
    return 0;
}