#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a),EEE##i=(b);i<=EEE##i;i++)
#define REV(i,a,b) for(int i=(a),EEE##i=(b);i>=EEE##i;i--)
#define CLOSE_TIE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define psbk push_back
#define endl '\n'
template<typename T>
void _outval(string s,int p,const T &t){cout<<s.substr(p,s.size()-p)<<'='<<t<<endl;}
template<typename T,typename... Args>
void _outval(string s,int p,const T &t,const Args &...rest){
    string n;
    while(s[p]!=',') n+=s[p++];
    cout<<n<<'='<<t<<' ';
    _outval(s,p+1,rest...);
}
#define outval(...) _outval(#__VA_ARGS__,0,__VA_ARGS__)
#define outarr(aaa,be,ed)\
{cout<<(#aaa)<<": ";\
FOR(iiii,be,ed) cout<<'['<<iiii<<"]="<<aaa[iiii]<<(iiii==ed?endl:' ');}
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
struct Edge{
    int u,v;
    ll w;
}ed[M];
int n,m,k;
ll c[N],a[K][N],f[N+K],ans=1e15;
vector<Edge> e,g;
int find(int p){return f[p]==p?p:f[p]=find(f[p]);}
void solve(int ID){
    int cnt=0,tot=m;
    ll res=0;
    FOR(i,1,k)
        if(ID&(1<<i-1)){
            FOR(j,1,n) e.psbk({n+cnt+1,j,a[i][j]});
            res+=c[i],++cnt,tot+=n;
        }
    sort(e.begin(),e.end(),[&](Edge a,Edge b){return a.w<b.w;});
    vector<int> ext[K];
    FOR(i,1,n+cnt) f[i]=i;
    int sum=0;
    FOR(i,0,e.size()-1)
        if(find(e[i].u)!=find(e[i].v)){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            //outval(i,u,v,w);
            f[find(e[i].u)]=find(e[i].v);
            if(e[i].u>n) ext[e[i].u-n].psbk(i);
            res+=w;
            ++sum;
            if(sum==n+cnt-1) break;
        }
    FOR(i,1,cnt)
        if(ext[i].size()==1){
            res-=e[ext[i][0]].w;
        }
    ans=min(ans,res);
    //outval(ID,res);
    e=g;
}
int main(){
    CLOSE_TIE
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //freopen("road/road4.in","r",stdin);
    cin>>n>>m>>k;
    FOR(i,1,m){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
        e.psbk(ed[i]);
    }
    ll mx=0;
    FOR(i,1,k){
        cin>>c[i];
        mx=max(mx,c[i]);
        FOR(j,1,n){
            cin>>a[i][j];
        }
    }
    FOR(i,1,n) f[i]=i;
    sort(e.begin(),e.end(),[&](Edge a,Edge b){return a.w<b.w;});
    FOR(i,0,e.size()-1)
        if(find(e[i].u)!=find(e[i].v)){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            //outval(i,u,v,w);
            f[find(u)]=find(v);
            g.psbk(e[i]);
            ans+=w;
        }
    e.clear();
    e=g;
    if(!mx){
        FOR(i,1,k){
            FOR(j,1,n)
                if(!a[i][j]){
                    FOR(k,1,n) e.psbk({j,k,a[i][k]});
                    break;
                }
        }
        ll res=0;
        FOR(i,1,n) f[i]=i;
        sort(e.begin(),e.end(),[&](Edge a,Edge b){return a.w<b.w;});
        FOR(i,0,e.size()-1)
            if(find(e[i].u)!=find(e[i].v)){
                int u=e[i].u,v=e[i].v,w=e[i].w;
                //outval(i,u,v,w);
                f[find(u)]=find(v);
                res+=w;
            }
        ans=min(ans,res);
        cout<<ans<<endl;
        return 0;
    }
    FOR(i,0,(1<<k)-1){
        solve(i);
    }
    cout<<ans<<endl;
    return 0;
}
