#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
namespace hcx{
    pair<ll,pair<int,int> > edges[12010000];
    pair<ll,pair<int,int> > edges2[12010000];
    ll c[22],a[22][1100000];
    int fa[1100000];
    int get_fa(int x){
        if(fa[x]==x)return x;
        return fa[x]=get_fa(fa[x]);
    }
    ll kruskal(int n,int m){
        for(int i=1;i<=n;i++)fa[i]=i;
        //cerr<<n<<" "<<m<<"\n";
        ll cnt=0,res=0;
        sort(edges2+1,edges2+m+1);
        for(int i=1;i<=m;i++){
            int u=edges2[i].second.first;
            int v=edges2[i].second.second;
            assert(u<=n&&v<=n);
            //cerr<<edges2[i].first<<"\n";
            if(get_fa(u)!=get_fa(v)){
                //cout<<get_fa(u)<<" "<<get_fa(v)<<"\n";
                fa[get_fa(u)]=get_fa(v);
                //cout<<fa[u]<<" "<<fa[v]<<"\n";
                res+=edges2[i].first;
                cnt++;
            }
            if(cnt==n-1)break;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<get_fa(i)<<" ";
        // }
        // cerr<<n<<" "<<cnt<<"\n";
        //cerr<<res<<"\n";
        return res;
    }
    void main(){
        int n,m,k;
        cin>>n>>m>>k;
        //cerr<<INT_MAX<<"\n";
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges[i]=make_pair(w,make_pair(u,v));
        }
        bool spe=1;
        for(int i=1;i<=k;i++){
            cin>>c[i];
            spe&=c[i]==0;
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        if(spe&&n<=1000){
            for(int i=1;i<=m;i++)edges2[i]=edges[i];
            int idx=m;
            for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                    for(int l=j+1;l<=n;l++){
                        edges2[++idx]=make_pair(a[i][j]+a[i][l],make_pair(j,l));
                    }
                }
            }
            cout<<kruskal(n,idx)<<"\n";
            return;
        }
        int z=1<<k;
        ll ans=LLONG_MAX;
        for(int i=0;i<z;i++){
            int cnt=n,idx=m;
            for(int j=1;j<=m;j++){
                edges2[j]=edges[j];
            }
            ll res=0;
            for(int j=1;j<=k;j++){
                if((i>>(j-1))&1){
                    cnt++;
                    res+=c[j];
                    for(int l=1;l<=n;l++){
                        edges2[++idx]=make_pair(a[j][l],make_pair(l,cnt));
                    }
                }
            }
            if(res>=ans)continue;
            ans=min(ans,kruskal(cnt,idx)+res);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    hcx::main();
    return 0;
}