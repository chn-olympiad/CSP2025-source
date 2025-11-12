#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int n,m;
string s;
int c[505];
bool vis[505];
ll ans=0;
void solve(int t,int fl,int res){
    if(t==n+1){
        if(res>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(c[i]>fl){
            vis[i]=1;
            if(s[t]=='0')solve(t+1,fl+1,res);
            else solve(t+1,fl,res+1);
            vis[i]=0;
        }
        else {
            vis[i]=1;
            solve(t+1,fl+1,res);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    solve(1,0,0);
    printf("%lld\n",ans);
}
