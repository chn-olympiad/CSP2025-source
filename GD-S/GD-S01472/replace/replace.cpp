#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <map>

using namespace std;

#define fori(i,a,b)     for(int i=(a);i<=(b);i++)
#define fori0(i,a,b)    for(int i=(a);i<(b);i++)
#define ford(i,a,b)     for(int i=(a);i>=(b);i--)
#define rgall(a)        (a).begin(),(a).end()
#define rgany(a,l,r)    (a).begin()+(l),(a).begin()+(r)
#define rgn(a,n)        rgany(a,0,n)
#define rgo1(a,n)       rgany(a,1,n+1)
#define fr first
#define sc second

ifstream cin("replace.in");
ofstream cout("replace.out");

typedef long long ll;

struct qry
{
    int a,b,w,i;
    bool operator<(const qry& c)const
    {
        return b>c.b;
    }
};
struct pairstr
{
    int l,r;
    pair<ll,ll> a,b;
    bool operator<(const pairstr& c)const
    {
        return a<c.a||a==c.a&&b<c.b;
    }
};
struct trie_node
{
    int l,r;
    array<int,26> vc;
};

array<vector<qry>,200001>   va,vq;
array<trie_node,5001001>    trie; // Root at 0
array<pairstr,200001>       vsa,vsq;
array<string,200001>        vp,vn,qp,qn;
array<int,2000001>          bidt,anss;
array<int,200001>           vla,vlb,vra,vrb,vua,vub;
map<pairstr,int>            vi;
bitset<200001>              vis,viq;
constexpr ll                P=(ll)1e15+37,P2=(ll)1e15+91,B=29,B2=37;
vector<int>                 vs;
string                      s,t;
int                         cntn,curn;

bool isprime(ll a)
{
    for(ll i=2;i*i<=a;i++)
        if(!(a%i))
            return false;
    return true;
}

int insert(const string& s,bool tp)//1 for insert
{
    int u=0;
    for(char i:s)
    {
        int& v=trie[u].vc[i-'a'];
        if(!v)
            if(tp)
                v=++cntn;
            else
                return -1;
        u=v;
    }
    return u;
}
void DFS(int u)
{
    trie[u].l=++curn;
    fori(i,0,25)
        if(trie[u].vc[i])
            DFS(trie[u].vc[i]);
    trie[u].r=curn;
}

inline pairstr f(string& pre,string& nxt)
{
    int l=0,r=0,m=s.size()-1;
    pair<ll,ll> res1={},res2={};
    while(s[l]==t[l])
        ++l;
    while(s[m-r]==t[m-r])
        ++r;
    ford(i,l-1,0)
        pre+=s[i];
    fori(i,m-r+1,m)
        nxt+=s[i];
    fori(i,l,m-r)
        res1.fr=(res1.fr*B+s[i]-'a'+1)%P,res1.sc=(res1.sc*B2+s[i]-'a'+1)%P2,
        res2.fr=(res2.fr*B+t[i]-'a'+1)%P,res2.sc=(res2.sc*B2+t[i]-'a'+1)%P2;
    return (pairstr){l,r,res1,res2};
}
void update(int i,int a,int n)
{
    while(i<=n)
        bidt[i]+=a,i+=i&-i;
}
int query(int i)
{
    int res=0;
    while(i)
        res+=bidt[i],i-=i&-i;
    return res;
}

typedef decltype(vra) rgarr;
typedef decltype(qp) sarr;
void solve_trie(int n,int q,rgarr& vl,rgarr& vr,rgarr& vu,const sarr& vs,const sarr& qs)
{
    fori(i,1,q)
        if(!viq[i])
            vu[i]=insert(qs[i],true);
    fori(i,1,n)
        if(!vis[i])
            vl[i]=insert(vs[i],false);
    DFS(0);
    fori(i,1,n)
        if(!vis[i])
        {
            int u=vl[i];
            if(u<0)
                continue;
            vl[i]=trie[u].l,vr[i]=trie[u].r;
        }
    fori(i,1,q)
        if(!viq[i])
            vu[i]=trie[vu[i]].l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // fori(i,1,100)
    //     if(isprime((ll)1e15+i))
    //         cout<<(ll)1e15+i<<' ';
    // cout<<isprime(P)<<isprime(P2);
    // return 0;
    int n,q,cnts=0;
    cin>>n>>q;
    fori(i,1,n)
    {
        cin>>s>>t;
        if(s==t)
        {
            vis.set(i);
            continue;
        }
        vsa[i]=f(vp[i],vn[i]);
    }
    fori(i,1,q)
    {
        cin>>s>>t;
        if(s.size()!=t.size())
        {
            viq.set(i);
            continue;
        }
        vsq[i]=f(qp[i],qn[i]);
    }

    solve_trie(n,q,vla,vra,vua,vp,qp);
    fori(i,0,cntn)
        trie[i].vc.fill(trie[i].l=trie[i].r=0);
    cntn=curn=0;
    solve_trie(n,q,vlb,vrb,vub,vn,qn);

    fori(i,1,n)
    {
        if(vis[i])
            continue;
        if(vla[i]<0||vlb[i]<0)
            continue;
        auto a=vsa[i];
        if(!vi.count(a))
            vi[a]=++cnts;
        int b=vi[a];
        // cout<<i<<' '<<b<<' '<<vla[i]<<' '<<vra[i]<<' '<<vlb[i]<<' '<<vrb[i]<<endl;
        va[b].push_back((qry){vra[i],vrb[i],1});
        va[b].push_back((qry){vla[i]-1,vrb[i],-1});
        va[b].push_back((qry){vra[i],vlb[i]-1,-1});
        va[b].push_back((qry){vla[i]-1,vlb[i]-1,1});
    }
    //   cout<<endl;
    fori(i,1,q)
    {
        if(viq[i])
            continue;
        auto a=vsq[i];
        if(!vi.count(a))
            continue;
        // cout<<i<<' '<<vi[a]<<' '<<vua[i]<<' '<<vub[i]<<'\n';
        // if(vua[i]<0||vub[i]<0)
        //     continue;
        vq[vi[a]].push_back((qry){vua[i],vub[i],0,i});
    }

    // fori(i,1,n)
    // {
    //     if(!vi.count(a))
    //         vi[a]=++cnts;
    //     va[vi[a]].push_back((qry){a.l,a.r,i});
    // }
    fori(i,1,cnts)                       //remember when a=0 do not update
    {
        sort(rgall(va[i])),sort(rgall(vq[i]));
        for(const auto& j:va[i])
            vs.push_back(j.a);
        for(const auto& j:vq[i])
            vs.push_back(j.a);
        sort(rgall(vs)),vs.erase(unique(rgall(vs)),vs.end());
        for(auto& j:va[i])
            j.a=lower_bound(rgall(vs),j.a)-vs.begin()+1;
        for(auto& j:vq[i])
            j.a=lower_bound(rgall(vs),j.a)-vs.begin()+1;
        int j=0;
        const int m=vs.size();
        for(const auto& k:vq[i])
        {
            // cout<<k.a<<' '<<k.b<<' '<<k.i<<endl;
            while(j<va[i].size()&&va[i][j].b>=k.b)
                update(m+1-va[i][j].a,va[i][j].w,m),++j;
            anss[k.i]=query(m+1-k.a);
            // for(const auto& l:va[i])
            // {
            //     cout<<l.a<<','<<l.b<<' '<<l.i<<endl;
            //     if(k.a>=l.a&&k.b>=l.b)
            //         ++anss[k.i];
            // }
        }
        fori(i,1,m)
            bidt[i]=0;
    }
    fori(i,1,q)
        cout<<anss[i]<<'\n';
    return 0;
}
