#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define ll long long
#define MAXN 10060
#define MAXM 1500000
#define MAXK 15
using namespace std;
struct edg{
    ll u,v,w;
    bool operator<(const edg& oth){
        return w<oth.w;//rev
    }
};
ll n,m,k,u,v,w,ans,final_answer=INT_MAX,rev[MAXK];
//vector<edg> edge[MAXN+5];
vector<edg> iniedge,edge,oth[MAXK],oper;
ll fa[MAXN+5],siz[MAXN+5],mn[MAXN+5];//c[MAXK+5][MAXN+5];
vector<ll> c[MAXK+5];
void init(){
    for(int i=1;i<=n+k;i++)
        fa[i]=i,siz[i]=1;//change
}
int find(int x){
    //cout<<"INFIND"<<x<<endl;
    if(fa[x]!=x){
        //cout<<"INFIND1"<<endl;
        return fa[x]=find(fa[x]);
    }
    //cout<<"INFIND2"<<endl;
    return x;
}
int merge(int a,int b){
    //cout<<"MERGE"<<a<<' '<<b<<endl;
    a=find(a),b=find(b);
    if(a==b) return 0;
    if(siz[a]<siz[b]) swap(a,b);
    fa[b]=a;
    siz[a]+=siz[b];
    return a;
}
signed main(){
    //freopen("/home/csps/ans/T2/road/road4.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        iniedge.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            ll a;
            cin>>a;
            c[i].push_back(a);
            if(j){
                oth[i].push_back({n+i,j,a});
            }
            //cin>>c[i][j];
        }
        sort(oth[i].begin(),oth[i].end());
    }
    sort(iniedge.begin(),iniedge.end());
    init();
    int fin=n;
    //cout<<"OUT1"<<endl;
    for(int i=0;i<m;i++){
        if(fin==1) break;
        if(merge(iniedge[i].u,iniedge[i].v)){
            //cout<<"IN"<<i<<endl;
            fin--;
            edge.push_back(iniedge[i]);
        }
    }
    oth[0]=edge;
    //cout<<"OUT"<<endl;
    for(int t=0,ed=(1<<k);t<ed;t++){
        for(int i=0;i<=k;i++)
            rev[i]=0;
        ans=0;
        init();
        vector<int> eve,_at;
        eve.push_back(0),_at.push_back(0);
        int fin=n;
        for(int w=1;w<=k;w++){
            if((t>>(w-1))&1){
                eve.push_back(w);
                _at.push_back(0);
                rev[w]=eve.size()-1;
                ans+=c[w][0];
                fin++;
            }
        }
        //for(int i=0;i<eve.size();i++){
          //  for(int j=0;j<oth[eve[i]].size();j++)
            //    cout<<oth[eve[i]][j].u<<' '<<oth[eve[i]][j].v<<endl;
        //}
        while(fin>1){
            //cout<<"IN"<<fin<<endl;
            edg mn={0,0,INT_MAX};
            for(int i=0,ed=eve.size();i<ed;i++){
                if(_at[i]<oth[eve[i]].size()){
                    if(oth[eve[i]][_at[i]]<mn)
                        mn=oth[eve[i]][_at[i]];
                    //cout<<"HAVE"<<endl;
                }
            }
            //cout<<"VAL"<<mn.u<<' '<<mn.v<<endl;
            //for(int i=0;i<eve.size();i++)
                //cout<<eve[i]<<' '<<_at[i]<<endl;
            if(merge(mn.u,mn.v)){
                ans+=mn.w;
                fin--;
            }
            if(mn.u<=n){
                _at[0]++;
            }else{
                //cout<<"MUST"<<mn.u-n<<endl;
                _at[rev[mn.u-n]]++;
            }
            if(!mn.u){
                //cout<<"OVER"<<endl;
                return 0;
            }
        }
        //cout<<"CURR"<<t<<endl;
        /*cout<<t<<":";
        for(int i=1;i<=n;i++)
            cout<<mn[i]<<endl;
        cout<<ans<<endl;*/
        //kru();
        final_answer=min(final_answer,ans);
    }
    cout<<final_answer<<endl;
    return 0;
}
/*
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define ll long long
#define MAXN 10000
#define MAXM 1000000
#define MAXK 10
using namespace std;
struct edg{
    ll u,v,w;
    bool operator<(const edg& oth){
        return w<oth.w;//rev
    }
};
ll n,m,k,u,v,w,ans,final_answer=INT_MAX;
//vector<edg> edge[MAXN+5];
vector<edg> iniedge,edge;
ll fa[MAXN+5],siz[MAXN+5],mn[MAXN+5],c[MAXK+5][MAXN+5];
void init(){
    for(int i=1;i<=n;i++)
        fa[i]=i,siz[i]=1,mn[i]=INT_MAX/5;//change
}
int find(int x){
    //cout<<"INFIND"<<x<<endl;
    if(fa[x]!=x){
        //cout<<"INFIND1"<<endl;
        return fa[x]=find(fa[x]);
    }
    //cout<<"INFIND2"<<endl;
    return x;
}
int merge(int a,int b){
    //cout<<"MERGE"<<a<<' '<<b<<endl;
    a=find(a),b=find(b);
    if(a==b) return 0;
    if(siz[a]<siz[b]) swap(a,b);
    fa[b]=a;
    siz[a]+=siz[b];
    mn[a]=min(mn[a],mn[b]);
    return a;
}
void kru(){
    set<pair<ll,ll>> st;
    for(int i=1;i<=n;i++)
        st.insert({mn[i],i});
    for(int i=0;;){
        if(st.size()<=1) break;
        ll tmn=st.begin()->first+next(st.begin())->first;
        ll emn=INT_MAX;
        if(i<n-1) emn=edge[i].w;
        //cout<<"Inner"<<i<<":"<<tmn<<' '<<emn<<endl;
        if(tmn<emn){
            ans+=tmn;
            ll a=st.begin()->second,b=next(st.begin())->second;
            st.erase(st.begin());
            st.erase(st.begin());
            ll w=merge(a,b);
            st.insert({mn[w],w});
        }else{
            ans+=emn;
            ll u=find(edge[i].u),v=find(edge[i].v);
            st.erase({mn[u],u});
            st.erase({mn[v],v});
            ll w=merge(u,v);
            st.insert({mn[w],w});
            i++;
        }
    }
}//2147483647
 //5182974424
signed main(){
    freopen("/home/csps/ans/T2/road/road4.in","r",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        iniedge.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
        }
    }
    sort(iniedge.begin(),iniedge.end());
    init();
    int fin=n;
    //cout<<"OUT1"<<endl;
    for(int i=0;i<m;i++){
        if(fin==1) break;
        if(merge(iniedge[i].u,iniedge[i].v)){
            //cout<<"IN"<<i<<endl;
            fin--;
            edge.push_back(iniedge[i]);
        }
    }
    //cout<<"OUT"<<endl;
    for(int t=0,ed=(1<<k);t<ed;t++){
        ans=0;
        init();
        for(int w=1;w<=k;w++){
            if((t>>(w-1))&1){
                ans+=c[w][0];
                for(int i=1;i<=n;i++)
                    mn[i]=min(mn[i],c[w][i]);
            }
        }
        //cout<<"CURR"<<t<<endl;
        /*cout<<t<<":";
        for(int i=1;i<=n;i++)
            cout<<mn[i]<<endl;
        cout<<ans<<endl;//
        kru();
        final_answer=min(final_answer,ans);
    }
    cout<<final_answer<<endl;
    return 0;
}

*/
