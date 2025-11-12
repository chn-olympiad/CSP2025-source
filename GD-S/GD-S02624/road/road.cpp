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

void main_init()
{

}
cint N=1.02e4,M=1.02e6,N2=10,P=1<<N2;
int n,n2,m,m0,n20,n21,p0,p1;
struct Ed
{
    int x,y;
    LL w;
};
bool operator < (const Ed &w1,const Ed &w2)
{
    return (w1.w<w2.w);
}
Ed ed_[M],ed[N];
struct UF
{
    int uf[N];
    void init()
    {
        For(i,1,n) uf[i]=i;
    }
    void init2()
    {
        For(i,1,n+n2) uf[i]=i;
    }
    int fin(int w)
    {
        return ((uf[w]==w)?w:(uf[w]=fin(uf[w])));
    }
    void mer(int w1,int w2)
    {
        uf[fin(w1)]=fin(w2);
    }
}uf;
LL cst[N2];
Ed cs[N2][N];
vct <Ed> v[P];
void work(int k,bool f)
{
    vct <Ed> g;
    if(k==(k&-k))
    {
        For_(j,0,n2) if(k>>j&1)
            For(i,1,n) g.pb(cs[j][i]);
        For(i,1,m0) g.pb(ed[i]);
    }
    else
    {
        int j0=__lg(k&-k);
        g=v[k&(k-1)];
        For(i,1,n) g.pb(cs[j0][i]);
    }
    sort(all(g));
    int len=sz(g);
    uf.init2();
    For_(i,0,len)
    {
        int x=g[i].x,y=g[i].y;
        if(uf.fin(x)!=uf.fin(y))
        {
            uf.mer(x,y);
            if(x>n||f) v[k].pb(g[i]);
        }
    }
}
cLL inf=1e18;
void main_solve()
{
    scanf("%d%d%d",&n,&m,&n2);
    n20=n2>>1; n21=n2-n20; p0=1<<n20; p1=1<<n21;
    For(i,1,m) scanf("%d%d%lld",&ed_[i].x,&ed_[i].y,&ed_[i].w);
    sort(ed_+1,ed_+m+1);
    uf.init();
    m0=0;
    For(i,1,m)
    {
        int x=ed_[i].x,y=ed_[i].y;
        if(uf.fin(x)!=uf.fin(y))
        {
            uf.mer(x,y);
            ed[++m0]=ed_[i];
        }
    }
    For_(j,0,n2)
    {
        scanf("%lld",&cst[j]);
        For(i,1,n)
        {
            scanf("%lld",&cs[j][i].w);
            cs[j][i].x=n+j+1,cs[j][i].y=i;
        }
        sort(cs[j]+1,cs[j]+n+1);
    }
    For_(k,0,p0) work(k,false); For_(k,0,p1) work(k<<n20,true);
    LL ans=inf;
    For_(k1,0,p0) For_(k2_,0,p1)
    {
        LL sum=0ll;
        int k2=(k2_<<n20),k; k=(k1|k2);
        For_(j,0,n2) if(k>>j&1) sum+=cst[j];
        int len1=sz(v[k1]),len2=sz(v[k2]);
        uf.init2();
        int l1=0,l2=0;
        Ed t;
        while(l1<len1||l2<len2)
        {
            if(l1<len1&&(l2>=len2||v[k1][l1].w<v[k2][l2].w))
                t=v[k1][l1++];
            else
                t=v[k2][l2++];
            if(uf.fin(t.x)!=uf.fin(t.y))
            {
                uf.mer(t.x,t.y);
                sum+=t.w;
            }
        }
        if(sum<ans) ans=sum;
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    main_init();
    // int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}