#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+11;
int cnt[5],a[N][5],sum=0,n,ans=-1e9;
bool vis[N][5],done=false;
void dfs(int i){
    int maxi=-1e9;
    int t;
    rep(j,1,3){
        if(maxi<=a[i][j]&&vis[i][j]==false){
            maxi=a[i][j];
            t=j;
        }
    }
    vis[i][t]=true;
    cnt[t]++;
    if(cnt[t]>n/2){
        cnt[t]--;
        return;
    }
    sum+=maxi;
    if(i+1>n){
        done=true;
        return;
    }
    rep(j,1,3){
        if(done==true) return;
        dfs(i+1);
    }
    rep(j,1,3) vis[i+1][j]=false;
    sum-=maxi;
    dfs(i);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        sum=0,done=false;
        memset(cnt,0,sizeof cnt);
        rep(i,1,n)
            rep(j,1,3) vis[i][j]=false;
        rep(i,1,n)
            rep(j,1,3){
                cin>>a[i][j];
            }

        rep(i,1,3){
            rep(k,1,n-1)
                rep(j,1,3) vis[k+1][j]=false;
            dfs(1);
            ans=max(ans,sum);
            sum=0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
