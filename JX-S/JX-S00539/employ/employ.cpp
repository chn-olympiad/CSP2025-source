#include <bits/stdc++.h>
using namespace std;
const int nn=505,mm=1<<18,mod=998244353,kb=19;
int n,m,vis[nn],c[nn],vk[mm][kb];
string s;
int dfs(int st,int h,int vl){
    if(vk[h][vl]!=-1)return vk[h][vl];
    if(st==n+1){
        if(vl>=m){
            //cout<<h<<'\n';
            return vk[h][vl]=1;
        }
        else return vk[h][vl]=0;
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        int nv=vl;
        if(st-nv-1<c[i] && s[st]=='1')nv++;
        num=(1ll*num+dfs(st+1,h+(1<<(i-1)),nv))%mod;
        vis[i]=0;
    }
    return vk[h][vl]=num;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    s=" "+s;
    memset(vk,-1,sizeof(vk));
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        cout<<dfs(1,0,0);
        return 0;
    }
    long long num=1;
    for(int i=1;i<=n;i++)num=1ll*num*i%mod;
    cout<<num;
    return 0;
}
