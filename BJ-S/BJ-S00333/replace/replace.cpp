#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INPUT_FILE "replace.in"
#define OUTPUT_FILE "replace.out"
constexpr int N=2e5+3;
constexpr int L=2.5e6+3;
constexpr int CH=26;
constexpr int D=13;
struct AC_auto
{
    int tr[L][CH]{},fail[L]{},tot=1,idx[N]{},dfn[L]{},low[L]{},anc[D][L]{},len[L]{},cnt=0;
    void insert(const string &str,int id)
    {
        int pos=1;
        for(char c:str)
        {
            if(!tr[pos][c-'a'])
            {
                tr[pos][c-'a']=++tot;
                len[tot]=len[pos]+1;
            }
            pos=tr[pos][c-'a'];
        }
        idx[id]=pos;
    }
    int next(int x,char c)const
    {
        return tr[x][c-'a'];
    }
    void build_fail()
    {
        static queue<int> q;
        fill_n(tr[0],CH,1);
        fail[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            // printf("fail[%d]:%d\n",u,fail[u]);
            for(int i=0;i<CH;i++)
            {
                int &v=tr[u][i];
                // printf("b %d ->%c %d\n",u,i+'a',v);
                if(v) fail[v]=tr[fail[u]][i],q.push(v);
                else v=tr[fail[u]][i];
                // printf("a %d ->%c %d\n",u,i+'a',v);
            }
        }
    }
    vector<int> g[L];
    void dfs(int u)
    {
        dfn[u]=++cnt;
        for(int v:g[u])
            dfs(v);
        low[u]=cnt;
    }
    int jump(int x,int h)const
    {
        for(int i=min(D-1,(int)__lg(tot));i>=0;i--)
            while(anc[i][x]&&len[anc[i][x]]>=h)
                x=anc[i][x];
        return anc[0][x];
    }
    void build_tree()
    {
        for(int i=2;i<=tot;i++)
        {
            g[fail[i]].push_back(i);
            anc[0][i]=fail[i];
        }
        for(int i=1;1<<i<=tot&&i<D;i++)
            for(int j=1;j<=tot;j++)
                anc[i][j]=anc[i-1][anc[i-1][j]];
        dfs(1);
    }
    void output()
    {
        for(int i=1;i<=tot;i++)
            for(int j=0;j<CH;j++)
                if(tr[i][j]) printf("%d %d %c\n",i,tr[i][j],j+'a');
    }
    void output_fail()
    {
        for(int i=2;i<=tot;i++)
            printf("%d %d\n",fail[i],i);
        for(int i=1;i<=tot;i++)
            printf("%d: [%d,%d]\n",i,dfn[i],low[i]);
    }
} ac1,ac2;
struct Point
{
    // type=0 for modify, type=1 for query
    bool type;
    int x,l,r,id,w;
    bool operator<(const Point &rhs)const
    {
        return x!=rhs.x?x<rhs.x:type<rhs.type;
    }
};
int n,q;
struct BIT
{
    static inline int lowbit(int x){return x&-x;}
    int c[L];
    void add(int x,int k)
    {
        for(;x<=ac2.tot;x+=lowbit(x))
            c[x]+=k;
    }
    int query(int x)const
    {
        int res=0;
        for(;x;x-=lowbit(x))
            res+=c[x];
        return res;
    }
    void add(int l,int r,int x)
    {
        add(l,x);
        add(r+1,-x);
    }
} bit;
ll ans[N];
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        ac1.insert(s,i);
        ac2.insert(t,i);
    }
    // printf("ac1:\n");
    // ac1.output();
    // printf("ac2:\n");
    // ac2.output();
    ac1.build_fail();
    ac2.build_fail();
    ac1.build_tree();
    ac2.build_tree();
    // ac1.output_fail();
    for(int i=1;i<=n;i++)
    {
        p.push_back({false,ac1.dfn[ac1.idx[i]],
            ac2.dfn[ac2.idx[i]],ac2.low[ac2.idx[i]],i,1});
        p.push_back({false,ac1.low[ac1.idx[i]]+1,
            ac2.dfn[ac2.idx[i]],ac2.low[ac2.idx[i]],i,-1});
    }
    for(int o=1;o<=q;o++)
    {
        string s,t;
        cin>>s>>t;
        int l=(int)s.size()-1,r=0;
        for(int i=0;i<s.size();i++)
            if(s[i]!=t[i])
            {
                l=i-1;
                break;
            }
        for(int i=(int)s.size()-1;i>=0;i--)
            if(s[i]!=t[i])
            {
                r=i+1;
                break;
            }
        // printf("l:%d r:%d\n",l,r);
        for(int i=0,pos1=1,pos2=1;i<s.size();i++)
        {
            pos1=ac1.next(pos1,s[i]);
            pos2=ac2.next(pos2,t[i]);
            // printf("i:%d pos1:%d pos2:%d\n",i,pos1,pos2);
            if(i<r-1||min(ac1.len[pos1],ac2.len[pos2])<i-l) continue;
            int len=i-l,tmp1=ac1.jump(pos1,len),tmp2=ac2.jump(pos2,len);
            p.push_back({true,ac1.dfn[pos1],ac2.dfn[pos2],0,o,1});
            p.push_back({true,ac1.dfn[pos1],ac2.dfn[tmp2],0,o,-1});
            p.push_back({true,ac1.dfn[tmp1],ac2.dfn[pos2],0,o,-1});
            p.push_back({true,ac1.dfn[tmp1],ac2.dfn[tmp2],0,o,1});
        }
    }
    sort(p.begin(),p.end());
    for(auto &&x:p)
    {
        // printf("type:%d x:%d l:%d r:%d id:%d w:%d\n",x.type,x.x,x.l,x.r,x.id,x.w);
        if(x.type) ans[x.id]+=bit.query(x.l)*x.w;
        else bit.add(x.l,x.r,x.w);
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
    return 0;
}
inline __attribute((constructor)) void init_io()
{
#ifdef INPUT_FILE
    freopen(INPUT_FILE,"r",stdin);
#endif
#ifdef OUTPUT_FILE
    freopen(OUTPUT_FILE,"w",stdout);
#endif
#ifndef RUN_ON_LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
#endif
}