#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    vector<array<int,3>> edge;
    vector<vector<int>> a(k+5,vector<int>(n+5));
    vector<int> c(k+5);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        edge.pb({u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    auto kruskal=[&]()->int
    {
        vector<int> fa(n+k+5);for(int i=1;i<=n+k;i++) fa[i]=i;
        auto find=[&](auto self,int x)->int
        {
            return fa[x]==x?x:fa[x]=self(self,fa[x]);
        };
        int sum=0;
        auto cmp=[](array<int,3> a,array<int,3> b)
        {
            return a[2]<b[2];
        };
        sort(edge.begin(),edge.end(),cmp);
        //for(auto j:edge) cout<<j[0]<<" "<<j[1]<<": "<<j[2]<<"\n";
        for(array<int,3> j:edge)
        {
            int u=j[0],v=j[1],w=j[2];
            int fu=find(find,u),fv=find(find,v);
            if(fv==fu) continue ;
            sum+=w;
            fa[fu]=fv;
        }
        return sum;
    };
    
    int mx=pow(2,k),ans=INT_MAX;
    for(int i=0;i<mx;i++)
    {
        int sum=0;
        vector<array<int,3>> g=edge;
        for(int j=0;j<k;j++)
        {
            if(i>>j&1)
            {
                sum+=c[j+1];
                for(int l=1;l<=n;l++)
                {
                    edge.pb({j+1+n,l,a[j+1][l]});
                }
            }
        }
        //cout<<i<<": "<<sum+kruskal()<<"\n";
        ans=min(ans,sum+kruskal());
        edge=g;
    }
    
    cout<<ans;
}
