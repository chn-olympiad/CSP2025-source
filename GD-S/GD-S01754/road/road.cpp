#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _iter(it,a) for (auto it=a.begin();it!=a.end();++it)
#define i32 signed
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

void read(int& a) {
    a=0;
    char c=getchar();
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) a=a*10+c-'0',c=getchar();
}

const int N=10015;
const int M=1100005;
const int K=15;
const i64 inf=1e18;

int n,m,k,idx;
int c[K];
int p[N];
i64 ans=inf;

struct node {
    int a,b,c;
    friend bool operator < (const node& a,const node& b) {
        return a.c<b.c;
    }
} arr[M],g[M];

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

int main() {
    FRR("road.in");
    FRW("road.out");
    read(n),read(m),read(k);
    _rep(i,1,m) {
        int a,b,c;
        read(a),read(b),read(c);
        g[i]={a,b,c};
    }
    sort(g+1,g+1+m);
    _rep(i,1,n) p[i]=i;
    _rep(i,1,m) {
        int a=g[i].a,b=g[i].b,c=g[i].c;
        if (find(a)==find(b)) continue;
        arr[++idx]={a,b,c};
        p[find(a)]=find(b);
    }
    _rep(i,1,k) {
        read(c[i]);
        _rep(j,1,n) {
            int a;
            read(a);
            arr[++idx]={n+i,j,a};
        }
    }
    sort(arr+1,arr+1+idx);
    _rep(t,0,(1<<k)-1) {
        i64 res=0;
        _rep(i,1,k) if ((t>>(i-1))&1) res+=c[i];
        _rep(i,1,n+k) p[i]=i;
        _rep(i,1,idx) {
            int a=arr[i].a,b=arr[i].b,c=arr[i].c;
            if (a>n && !((t>>(a-n-1))&1)) continue;
            if (b>n && !((t>>(b-n-1))&1)) continue;
            if (find(a)==find(b)) continue;
            p[find(a)]=find(b);
            res+=c;
            if (res>=ans) break;
        }
        ans=min(ans,res);
    }
    printf("%lld",ans);
    // TIMESTAMP
    return 0;
}

// 15:59