#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
struct dsu{
    int fa[maxn];
    void init(int n){up(i,1,n)fa[i]=i;}
    int fd(int u){if(u==fa[u])return u;return fa[u]=fd(fa[u]);}
    bool mr(int x,int y){x=fd(x),y=fd(y);if(x==y)return 0;fa[x]=y;return 1;}
}T;
int n,m,k,a[11][10005],c[11],col[maxn],fa[11];
pair<int,pi>E[maxn],E2[maxn],E3[maxn];
pair<int,pi> mn[11][11];
int rk[11][10005],buc[100005];
pair<int,pi> vc[maxn];
inline int fd(int u){if(u==fa[u])return u;return fa[u]=fd(fa[u]);}
void Sort(int m){
    up(i,1,n*k)buc[i]=0;
    up(i,1,m)buc[rk[E[i].p2.p1][E[i].p2.p2]]=1;int c=0;
    up(i,1,n*k)if(buc[i])E[++c]=vc[i];
}
void slv(){
    n=read(),m=read(),k=read();
    up(i,1,m)E[i].p2.p1=read(),E[i].p2.p2=read(),E[i].p1=read();
    up(i,1,n)T.fa[i]=i;sort(E+1,E+m+1);
    int top=0;up(i,1,m)if(T.mr(E[i].p2.p1,E[i].p2.p2))E2[++top]=E[i];
    int _=0;up(i,0,k-1){
        c[i]=read();
        up(j,1,n)a[i][j]=read(),vc[++_]=m_p(a[i][j],m_p(i,j));
    }
    sort(vc+1,vc+n*k+1);
    up(i,1,n*k)
        rk[vc[i].p2.p1][vc[i].p2.p2]=i,vc[i].p2.p1+=n+1;
    ll res=1e18;
    up(i,0,(1<<k)-1){
        ll s=0;up(j,0,k-1)if((i>>j)&1)s+=c[j];
        int top2=0;
        if(i){
            up(j,1,n){
                pi mn;mn.p1=2e9,mn.p2=0;
                up(p,0,k-1)if((i>>p)&1)mn=min(mn,{a[p][j],p});
                col[j]=mn.p2;E[++top2]={mn.p1,{mn.p2,j}};
            }
            up(p,0,k-1)up(q,0,k-1)mn[p][q]={2e9,{0,0}};
            up(p,0,k-1)if((i>>p)&1)up(j,1,n)mn[p][col[j]]=min(mn[p][col[j]],{a[p][j],{p,j}});
            up(p,0,k-1)fa[p]=p;
            vector<pair<pair<int,pi>,pi> >vc;
            up(p,0,k-1)if((i>>p)&1)up(q,0,k-1)if((i>>q)&1)
                vc.p_b({mn[p][q],{p,q}});
            sort(vc.begin(),vc.end());
            for(auto it:vc)
                if(fd(it.p2.p1)!=fd(it.p2.p2))fa[fd(it.p2.p1)]=it.p2.p2,E[++top2]=it.p1;
        }
        // if(top2)sort(E+1,E+top2+1);
        if(top2)Sort(top2);
        merge(E+1,E+top2+1,E2+1,E2+top+1,E3+1);T.init(n+k);
        up(i,1,top+top2)if(T.mr(E3[i].p2.p1,E3[i].p2.p2))s+=E3[i].p1;
        res=min(res,s);
    }
    cout<<res;
}
int main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    slv();
    return 0;
}