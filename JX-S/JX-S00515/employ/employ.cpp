#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5;
const int mod=998244353;
int n,m,s[N],c[N],ans,vis[N],a[N];
void solve15(){

}
void dfs(int pos){
    if(pos==n+1){
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(i-cnt-1<a[i] && s[i])
                cnt++;
        }
        if(cnt>=m)ans++;
        return;
    }
    for(int i=1;i<=n;++i){
        if(vis[i])continue;
        vis[i]=1;
        a[pos]=c[i];
        dfs(pos+1);
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        s[i]=c-'0';
    }
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    // if(m==n)solve15(),exit(0);
    dfs(1);
    cout<<ans;
    return 0;
}
// g++ /home/noi/Desktop/TTY/employ.cpp -o employ -std=c++14 -static

/*
3:23    finished O(2^n)
*/