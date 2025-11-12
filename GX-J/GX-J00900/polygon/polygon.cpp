#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
long long a[N],vis[N],vis2[N],n,ans=0;
map<string,bool> m2;
inline void dfs(long long s,long long sum,long long maxv,long long m){
    if(m>=3){
        if(sum>2*maxv){
            string s2;
            for(int i=1;i<=s;++i){
                s2+=(vis[i]+'0');
            }
            if(m2[s2]==0){
                ans++;m2[s2]=1;
            }
        }
    }
    //if(sum==10)cout<<maxv<<endl;
    if(s==n)return ;
    for(int i=s+1;i<=n;++i){
        if(!vis[i]){
            vis[i]=1;dfs(i,sum+a[i],max(maxv,a[i]),m+1);vis[i]=0;
        }
        dfs(i,sum,a[i],m);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans%mod<<endl;
    return 0;
}
