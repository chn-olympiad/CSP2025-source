#include<bits/stdc++.h>
using namespace std;using LL=int64_t;using LD=long double;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
#define endl '\n'
auto freo(string s){
    string in=s+".in";
    string out=s+".out";
    return make_pair(
        freopen(in.c_str(),"r",stdin),
        freopen(out.c_str(),"w",stdout)
    );
}
struct DSU{
    vector<int>p;
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    DSU(int n):p(n){
        iota(p.begin(),p.end(),0);
    }
    bool merge(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return false;
        return p[u]=v,true;
    }
};
int n,m,k;
struct edge{
    int u,v,w;
    bool operator<(edge oth){
        return w<oth.w;
    }
};
int main(){
    freo("road");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    vector<edge>e(m);
    for(auto&ee:e){
        cin>>ee.u>>ee.v>>ee.w;
    }
    sort(e.begin(),e.end());
    DSU dsu(n+1);
    LL ans=0;
    int lcnt=n;
    vector<edge>b;
    for(auto ee:e){
        if(lcnt==1)break;
        int u=ee.u,v=ee.v,w=ee.w;
        if(dsu.merge(u,v)){
            ans+=w,--lcnt;
            b.push_back(ee);
        }
    }
    // assert(lcnt==1&&true);
    int bw=b.back().w;
    // cerr<<"get b ok _ans="<<ans<<endl;
    vector<pair<int,vector<edge>>>ae(k);
    int new_id=n;
    for(auto&pve:ae){
        cin>>pve.first;
        auto &ve=pve.second;
        int id=++new_id;
        f(i,1,n){
            int w;cin>>w;
            if(w>=bw)continue;
            ve.push_back(edge{id,i,w});
        }
        sort(ve.begin(),ve.end());
    }
    fu(s,1,1<<k){
        bool flag=false;
        fu(i,0,k)if(s>>i&1){
            if(ae[i].second.empty())flag=true;
        }
        if(flag)continue;
        int lcnt=n;LL res=0;
        vector<edge>a=b;
        fu(i,0,k)if(s>>i&1){
            ++lcnt,res+=ae[i].first;
            auto &ve=ae[i].second;
            a.insert(a.end(),ve.begin(),ve.end());
        }
        sort(a.begin(),a.end());
        DSU dsu(new_id+1);
        for(auto ee:a){
            if(lcnt==1)break;
            if(dsu.merge(ee.u,ee.v))res+=ee.w,--lcnt;
        }
        if(lcnt==1)
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
//pas sample:15:25