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
typedef pair<u64,u64> pii;
typedef pair<int,pii> piii;

const int N=5000005;
const int P=131;

int n,q,m,tmp;
char a[N],b[N];
u64 pa[N],pb[N];
u64 pw[N];
map<u64,map<int,map<piii,int>>> st;

u64 solvea(int l,int r) {
    return pa[r]-pa[l-1]*pw[r-l+1];
}

u64 solveb(int l,int r) {
    return pb[r]-pb[l-1]*pw[r-l+1];
}

void init() {
    pw[0]=1;
    _rep(i,1,N-1) pw[i]=pw[i-1]*P;
}

int main() {
    FRR("replace.in");
    FRW("replace.out");
    init();
    scanf("%d %d",&n,&q);
    _rep(i,1,n) {
        scanf("%s %s",a+1,b+1);
        m=strlen(a+1);
        int fir=m+1;
        _rep(i,1,m) if (a[i]!=b[i]) {
            fir=i;
            break;
        }
        if (fir==m+1) continue;
        u64 cur=0;
        _rep(i,fir,m) if (a[i]!=b[i]) cur=cur*P+(i-fir+1);
        u64 ha=0,hb=0;
        _rep(i,1,m) ha=ha*P+(a[i]-'a'),hb=hb*P+(b[i]-'a');
        st[cur][fir-1][piii{m,pii{ha,hb}}]++;
        // cerr<<"test: "<<cur<<" "<<fir-1<<" "<<ha<<" "<<hb<<endl;
    }
    while (q--) {
        scanf("%s %s",a+1,b+1);
        m=strlen(a+1),tmp=strlen(b+1);
        if (m!=tmp) {
            puts("0");
            continue;
        }
        int fir=m+1;
        _rep(i,1,m) if (a[i]!=b[i]) {
            fir=i;
            break;
        }
        u64 cur=0;
        _rep(i,fir,m) if (a[i]!=b[i]) cur=cur*P+(i-fir+1);
        _rep(i,1,m) pa[i]=pa[i-1]*P+(a[i]-'a'),pb[i]=pb[i-1]*P+(b[i]-'a');
        int ans=0;
        _rep(i,0,fir-1) _iter(it,st[cur][i]) {
            int len=it->first.first;
            u64 A=it->first.second.first,B=it->first.second.second;
            int cnt=it->second;
            if (fir-i+len-1>m) continue;
            // cerr<<"check: "<<i<<" "<<fir-i<<" "<<fir-i+len-1<<" "<<solvea(fir-i,fir-i+len-1)<<" "<<solveb(fir-i,fir-i+len-1)<<endl;
            if (solvea(fir-i,fir-i+len-1)==A && solveb(fir-i,fir-i+len-1)==B) ans+=cnt;
        }
        printf("%d\n",ans);
    }
    // TIMESTAMP
    return 0;
}

/*
st[diff][prelen] -> (len1,a1,b1), (len2,a2,b2), (len3,a3,b3), ...
*/

// 16:57