#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node{
    int to,val;
};

signed main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

    int n,m,k,ans=0;
    bool f=true;

    cin>>n>>m>>k;

    vector<vector<node> >mp(n+1,vector<node>());
    vector<vector<int> >c(k+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        int u,v,w;

        cin>>u>>v>>w;

        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }

    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0) f=false;
        }
    }

if(k==0){
    vector<bool>vis(n+1,false);
    vector<int>d(n+1,INT_MAX);

    d[1]=0;

    for(int i=1;i<n-1;i++){
        int x=0,tmp=INT_MAX;

        for(int i=1;i<=n;i++){
            if(!vis[i]&&d[i]<tmp){
                tmp=d[i];
                x=i;
            }
        }

        vis[x]=true;

        for(int i=0;i<mp[x].size();i++){
            int nxt=mp[x][i].to,r=mp[x][i].val;
            if(r<d[nxt]) d[nxt]=r;
        }
    }

    for(int i=1;i<=n;i++){
        ans+=d[i];

    }

    cout<<ans<<endl;
}else if(f){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) {
                mp[i].push_back({j,0});
                mp[j].push_back({i,0});
            }
        }
    }
    vector<bool>vis(n+1,false);
    vector<int>d(n+1,INT_MAX);

    d[1]=0;

    for(int i=1;i<n-1;i++){
        int x=0,tmp=INT_MAX;

        for(int i=1;i<=n;i++){
            if(!vis[i]&&d[i]<tmp){
                tmp=d[i];
                x=i;
            }
        }

        vis[x]=true;

        for(int i=0;i<mp[x].size();i++){
            int nxt=mp[x][i].to,r=mp[x][i].val;
            if(r<d[nxt]) d[nxt]=r;
        }
    }

    for(int i=1;i<=n;i++){
        ans+=d[i];

    }

    cout<<ans<<endl;

}


}
