#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=2e6+5,M=1e7+5,mod=1e9+9;
int n,m,q,tt,id[M],sz[M],ans[N];
string A,B;
unordered_map<LL,int>mp;
struct BIT
{
    int a[M];
    inline void add(int w,int x){for(;w<=tt;w+=w&-w) a[w]+=x;}
    inline int ask(int w){int s=0;for(;w;w&=(w-1)) s+=a[w];return s;}
    inline int ask(int l,int r){return ask(r)-ask(l-1);}
}BT;
namespace T
{
    int nx[M][26];
    inline int ins(string S)
    {
        int w=0;
        for(char i:S)
        {
            int &t=nx[w][i-'a'];
            if(!t) t=++tt;w=t;
        }return w;
    }
    void dfs(int x=0)
    {
        id[x]=++tt;sz[x]=1;
        for(int i=0;i<26;i++) if(nx[x][i]) dfs(nx[x][i]),sz[x]+=sz[nx[x][i]];
    }
}
inline int H(string S)
{
    int s=0;
    for(char i:S) s=(2347ll*s+(i-'a'+1))%mod;
    return s;
}
inline int New(LL x,LL y)
{
    x=(1145141ll*x+y);
    if(!mp[x]) mp[x]=++m;
    return mp[x];
}
struct INFO{
    int u,v,x;
};
vector<INFO>ad[N],qr[N];
inline INFO IT(string A,string B,int I)
{
    int l=-1,r=-1,n=A.size();
    for(int i=0;i<n;i++) if(A[i]!=B[i]){l=i;break;}
    for(int i=n-1;~i;i--) if(A[i]!=B[i]){r=i;break;}
    string X,Y,C,D;
    for(int i=l;i<=r;i++) C+=A[i];
    for(int i=l;i<=r;i++) D+=B[i];
    
    for(int i=l-1;~i;i--) X+=A[i];
    for(int i=r+1;i<n;i++) Y+=A[i];

    int u=T::ins(X),v=T::ins(Y);

    return {u,v,New(H(C),H(D))};
}
// inline bool in(int x,int y){return id[y]<=id[x]&&id[x]<id[y]+sz[y];}
struct node{
    int x,y,v;
    bool operator<(node &X){return x<X.x;}
}P[N],Q[N];
int c1,c2;
inline void ad1(int u,int v)
{
    int l=id[u],r=id[u]+sz[u],L=id[v],R=id[v]+sz[v];
    P[++c1]={l,L,1};P[++c1]={r,R,1};
    P[++c1]={r,L,-1};P[++c1]={l,R,-1};
}
inline void ad2(int u,int v,int i)
{
    Q[++c2]={id[u],id[v],i};
}
inline void sol(vector<INFO>&A,vector<INFO>&B,int I)
{
    if(!A.size()||!B.size()) return;
    c1=0,c2=0;
    for(auto [u,v,_]:A) ad1(u,v);
    for(auto [u,v,i]:B) ad2(u,v,i);
    sort(P+1,P+1+c1);sort(Q+1,Q+1+c2);
    for(int i=1,j=1;i<=c2;i++)
    {
        while(j<=c1&&P[j].x<=Q[i].x) BT.add(P[j].y,P[j].v),j++;
        ans[Q[i].v]+=BT.ask(Q[i].y);
    }
    for(int i=1,j=1;i<=c2;i++)
    {
        while(j<=c1&&P[j].x<=Q[i].x) BT.add(P[j].y,-P[j].v),j++;
    }
    
    // for(auto [u,v,i]:B)
    // {
    //     for(auto [U,V,_]:A)
    //     {
    //         if(in(u,U)&&in(v,V)) ans[i]++;
    //     }
    // }
}
int main()
{
    fr(replace)
    cin.tie(0)->sync_with_stdio(0);cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>A>>B;
        if(A==B) continue;
        auto [u,v,x]=IT(A,B,i);
        ad[x].push_back({u,v,0});
    }
    for(int i=1;i<=q;i++)
    {
        cin>>A>>B;
        if(A.size()!=B.size()){ans[i]=0;continue;}
        auto [u,v,x]=IT(A,B,-i);
        qr[x].push_back({u,v,i});
        
    }
    tt=0;T::dfs();
    for(int i=1;i<=m;i++) sol(ad[i],qr[i],i);

    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}

//2701 3982