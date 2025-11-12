#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define x first
#define y second
#define all(a) (a).begin(),(a).end()
#define FRE(f) {freopen(f".in","r",stdin);freopen(f".out","w",stdout);}
#define LL long long
#ifdef DBZ
#define Z(x...) cerr<<"\t#"<<__LINE__<<" : ",db(#x,x),cerr<<"\n";
void db(const char*s){}
template<typename T,typename...TT>void db(const char*s,T x,TT...y){
	while((*s)&&(*s)!=',')cerr<<*s++;
	s++;
	cerr<<" = "<<x<<"  ";
	db(s,y...);
}
#define ZZ(a,l,r) cerr<<"\t@"<<__LINE__<<" : "<<#a<<" = ";fr(IT,l,r)cerr<<a[IT]<<" ";cerr<<"\n";
#else
#define Z(x...)
#define ZZ(x...)
#endif
// #define int LL
const int N=2e5+33,K=11,EN=2e6+33;
int n,m,k,c[N],a[K][N];
struct E{
    int u,v,w;
    bool operator<(E t){
        return w<t.w;
    }
}et[EN],e[EN];int ei;
LL ans=LLONG_MAX;

int fa[N],rk[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void mg(int x,int y){
    if(rk[x]>rk[y]){
        fa[y]=x;
    }else if(rk[y]>rk[x]){
        fa[x]=y;
    }else{
        fa[y]=x;
        rk[x]++;
    }
}
void pre(){
    sort(et+1,et+m+1);
    fr(i,1,n)fa[i]=i,rk[i]=0;
    fr(i,1,m){
        int u=et[i].u,v=et[i].v,w=et[i].w;
        u=find(u),v=find(v);
        if(u!=v){
            e[++ei]=et[i];
           if(rand()%2) mg(u,v);
        }
    }
}
int ord[N],pos[N],cnt[N];
int val[N],vi;
LL mst(){
    fr(i,0,vi)cnt[i]=0;
    fr(i,1,ei){
        Z(i,e[i].w);
        cnt[e[i].w]++;
    }
    pos[0]=cnt[0];
    fr(i,1,vi)pos[i]=pos[i-1]+cnt[i];
    assert(pos[vi]==ei);
    Z(ei,vi);
    ZZ(cnt,0,vi);
    
    fr(i,1,ei){
        ord[pos[e[i].w]--]=i;
    }
    ZZ(ord,0,ei);

    LL s=0;
    fr(i,1,n+k)fa[i]=i,rk[i]=0;
    fr(it,1,ei){
        int i=ord[it];
        int u=e[i].u,v=e[i].v,w=e[i].w;
        u=find(u),v=find(v);
        Z(i,u,v,w);
        if(u!=v){
            s+=val[w];
            mg(u,v);
        }
    }
    return s;
}
void lsh(){
    assert(vi==0);
    fr(i,1,ei){
        val[++vi]=e[i].w;
    }
    fr(i,1,k){
        fr(j,1,n){
            val[++vi]=a[i][j];
        }
    }
    sort(val+1,val+vi+1);
    vi=unique(val+1,val+vi+1)-val-1;
    #define F(x) (x)=(lower_bound(val+1,val+vi+1,x)-val)
    fr(i,1,ei){F(e[i].w);}
    fr(i,1,k)fr(j,1,n){F(a[i][j]);}
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    FRE("road");
    cin>>n>>m>>k;
    fr(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        et[i]={u,v,w};
    }
    pre();

    fr(i,1,k){
        cin>>c[i];
        fr(j,1,n){
            cin>>a[i][j];
        }
    }

    lsh();

    static E ori[N];
    int oe=ei;
    fr(i,1,oe)ori[i]=e[i],assert(e[i].w<=vi);
    fr(z,0,(1<<k)-1){
        fr(i,1,oe)e[i]=ori[i];
        ei=oe;

        LL cs=0;
        fr(i,1,k)if(z>>i-1&1){
            cs+=c[i];
            fr(j,1,n){
                e[++ei]={n+i,j,a[i][j]};
            }
        }
        LL nw=mst();
        Z(z,nw,cs);
        ans=min(ans,nw+cs);
    }
    cout<<ans<<"\n";
    return 0;
}
