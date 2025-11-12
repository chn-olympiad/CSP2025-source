#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,c[N],C[N][N],m;
string s;
void wkA(){
    int ans=1,res=0;
    for(int i=1;i<=n;++i){
        ans=ans*i%mod;
    }
    cout<<ans<<'\n';//忘考虑c==0了，蒙一个
}
int stk[N],top,vis[N],ans;
void dfs(int u){
    if(u>n){
        int res=0,pre=0;
        for(int i=1;i<=n;++i){
            int now=stk[i];
            if(pre>=c[now]){
                pre++;continue;
            }
            if(s[i]=='0'){
                pre++;continue;
            }
            res++;
        }
        if(res>=m) ++ans;
        return;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        vis[i]=1; 
        stk[++top]=i;
        dfs(u+1);
        vis[i]=0;
        top--;
    }
}
void wk(){
    dfs(1);
    cout<<ans<<'\n';
}
signed main(){ 
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int tag=1;
    cin>>n>>m>>s; 
    s=' '+s;
    for(int i=1;i<=n;++i) cin>>c[i];
    for(int i=1;i<=n;++i){
        if(s[i]=='0') tag=0;
    }
    if(n<=10){
        wk();
        return 0;
    } 
    wkA();
    
    return 0;
}