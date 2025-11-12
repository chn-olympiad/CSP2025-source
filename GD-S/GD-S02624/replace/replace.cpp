#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define vct vector
#define pb push_back
#define sz(ev) ((int)ev.size())
#define all(ev) ev.begin(),ev.end()
#define ft first
#define sc second
#define exc(e) if(e) continue
#define stop(e) if(e) break
#define ret(e) if(e) return 
using namespace std;


cLL base=166686661ll,mod=1686688681ll;
mt19937 gen(121);
cint K=26;
LL hh[K];
void main_init()
{
    For_(k,0,K) hh[k]=(llabs((LL)gen())%mod);
}
cint N=2.01e5,Q_=2.01e5,L=6e6,L_=5.01e6;
int n,Q;
char s1[L],s2[L];
map <ULL,int> mp;
array <int,2> gt()
{
    scanf("%s%s",s1+1,s2+1);
    int len=strlen(s1+1);
    if(strlen(s2+1)!=len) return (array<int,2>){-1,-1};
    int k1=1,k2=len;
    while(k1<=len&&s1[k1]==s2[k1]) k1++;
    if(k1>len) return (array<int,2>){-1,-1};
    while(k2>=1&&s1[k2]==s2[k2]) k2--;
    return (array<int,2>){k1,k2};
}
LL gths(char *str,int l,int r)
{
    LL w=0ll;
    For(i,l,r)
        w=(w*base+hh[str[i]-'a'])%mod;
    return w;
}
array <int,2> fin[N],fin2[Q_];
array <int,2> rts[N]; int tot;
int m1,m2;
struct Trie
{
    int id,idx;
    array <int,K> tr[L];
    int in[L],out[L];
    void init()
    {
        id=0;
    }
    int nnd()
    {
        id++;
        For_(k,0,K) tr[id][k]=0;
        return id;
    }
    int brk(int p,char *sl,char *sr)
    {
        for(char *i=sl;i<sr;i++)
        {
            int c=((*i)-'a');
            if(!tr[p][c]) tr[p][c]=nnd();
            p=tr[p][c];
        }
        return p;
    }
    int wal(int p,char *sl,char *sr)
    {
        for(char *i=sl;i<sr;i++)
        {
            int c=((*i)-'a');
            if(!tr[p][c]) return p;
            p=tr[p][c];
        }
        return p;
    }
    void init2()
    {
        idx=0;
    }
    void dfs(int p)
    {
        in[p]=out[p]=++idx;
        For_(k,0,K) if(tr[p][k])
        {
            dfs(tr[p][k]);
            out[p]=out[tr[p][k]];
        }
    }
}tr;
int ans[Q_];
cint M=L;
vct <array<int,3> > ad[M];
vct <array<int,2> > qs[M];
struct BIT
{
    int c[M];
    void init()
    {
        For(i,1,m2) c[i]=0;
    }
    void add(int k,int w)
    {
        for(int i=k;i<=m2;i+=(i&-i))
            c[i]+=w;
    }
    void add(int l,int r,int w)
    {
        add(l,w),add(r+1,-w);
    }
    int qry(int k)
    {
        int w=0;
        for(int i=k;i;i&=(i-1))
            w+=c[i];
        return w;
    }
}bt;
void main_solve()
{
    scanf("%d%d",&n,&Q);
    tot=0;
    For(i,1,n)
    {
        array <int,2> ran=gt();
        exc(!~ran[0]);
        ULL hs=((((ULL)gths(s1,ran[0],ran[1]))<<32)^((ULL)gths(s2,ran[0],ran[1])));
        // printf("hs=%llu\n",hs);
        int id=0;
        if(mp.find(hs)==mp.end())
        {
            id=++tot;
            rts[tot]=(array<int,2>){tr.nnd(),tr.nnd()};
            mp[hs]=id;
        }
        else id=mp[hs];
        reverse(s1+1,s1+ran[0]);
        int len=strlen(s1+1);
        fin[i][0]=tr.brk(rts[id][0],s1+1,s1+ran[0]);
        fin[i][1]=tr.brk(rts[id][1],s1+ran[1]+1,s1+len+1);
    }
    tr.init2();
    For(i,1,tot) tr.dfs(rts[i][0]);
    m1=tr.idx;
    tr.init2();
    For(i,1,tot) tr.dfs(rts[i][1]);
    m2=tr.idx;
    For(i,1,Q)
    {
        array <int,2> ran=gt();
        exc(!~ran[0]);
        ULL hs=((((ULL)gths(s1,ran[0],ran[1]))<<32)^((ULL)gths(s2,ran[0],ran[1])));
        // printf("hs=%llu\n",hs);
        int id=0;
        exc(mp.find(hs)==mp.end());
        id=mp[hs];
        reverse(s1+1,s1+ran[0]);
        int len=strlen(s1+1);
        fin2[i]=(array<int,2>){tr.wal(rts[id][0],s1+1,s1+ran[0]),tr.wal(rts[id][1],s1+ran[1]+1,s1+len+1)};
    }
    For(i,1,n) if(fin[i][0])
    {
        ad[tr.in[fin[i][0]]].pb((array<int,3>){tr.in[fin[i][1]],tr.out[fin[i][1]],1});
        ad[tr.out[fin[i][0]]+1].pb((array<int,3>){tr.in[fin[i][1]],tr.out[fin[i][1]],-1});
    }
    For(i,1,Q) if(fin2[i][0]) qs[tr.in[fin2[i][0]]].pb({tr.in[fin2[i][1]],i});
    bt.init();
    For(i,1,m1)
    {
        for(auto rn:ad[i]) bt.add(rn[0],rn[1],rn[2]);
        for(auto q:qs[i]) ans[q[1]]=bt.qry(q[0]);
    }
    For(i,1,Q) printf("%d\n",ans[i]);
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    main_init();
    // int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}