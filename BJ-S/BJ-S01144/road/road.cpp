#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define ull unsigned long long
//#define int long long
using namespace std;
const int N=1e4+11;
int n,m,k;
vector<pii> g[N];
int g2[N][N];
int c[N];
ll ans=1e9,ans2=1e9;
int usei[N][N];
int use[N][N],use2[N][N];
bool v[N];
bool check()
{
    rep(i,1,n){
        if(v[i]==0)return 0;
    }
    return 1;
}
void dfs(ll x,ll l){
    //cout<<"sou dao:"<<x<<" l="<<l<<"\n";
    v[x]=1;//cout<<"v["<<x<<"]=1\n";
    if(check()){
            //cout<<"succeed\n";
        if(l<ans2){
            ans2=l;
            rep(i,1,n){
                rep(j,1,n){
                    use2[i][j]=usei[i][j];
                }
            }
        }
        //cout<<"ans="<<ans<<"\n";
        return;
    }
    //cout<<"chu du "<<g[x].size()<<"\n";
    rep(i,0,g[x].size()-1){
        int u=g[x][i].first,w=g[x][i].second;
        if(v[u]==0){
            usei[x][u]=w;
            dfs(u,l+w);
            usei[x][u]=0;
        }
    }
    //cout<<"cong "<<x<<" hui tui\n";cout<<"v["<<x<<"]=0\n";
    v[x]=0;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);

    rep(i,1,m){int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    rep(l,1,n){
        rep(i,1,n)v[i]=0;
        dfs(1,0);
        if(ans>ans2){
            ans=ans2;
            rep(i,1,n){
                rep(j,1,n){
                    use[i][j]=use2[i][j];
                }
            }
        }
    }
    //cout<<"ans="<<ans<<"\n";
    int a[N];
    rep(i,1,k){
        scanf("%d",c+i);
        rep(j,1,n){
            scanf("%d",a+j);
            g2[i][j]=g2[j][i]=a[j];
        }
    }

ans--;
    rep(i,1,n){
        rep(j,1,n){
            if(use[i][j]==0)continue;
            rep(l,1,k){
                if(c[l]+g2[l][i]+g2[l][j]<=use[i][j]){
                        ans-=use[i][j];
                        ans=ans+c[l]+g2[l][i]+g2[l][j];
                        g2[l][i]=g2[l][j]=c[l]=0;
                    }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
/*

*/
