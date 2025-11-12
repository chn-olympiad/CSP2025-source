#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
inline void in (T &x) {
    char c; int f=1;
    do {c=getchar(); (c=='-')&&(f=-1);} while(c>'9'||c<'0');
    for (x=0;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}

const int N=1e5+5;
int n,lim;
struct node {
    int i,j,vl;
    inline bool operator < (const node &o) const {return vl>o.vl;}
} tmp[N][4];

int cnt[6]; ll ans;

inline void init () {
    in (n); ans=0;
    cnt[1]=cnt[2]=cnt[3]=0;
    for (int i=1,x,y,z;i<=n;++i) {
        in (x),in (y),in (z);
        tmp[i][1]={0,1,x},tmp[i][2]={0,2,y},tmp[i][3]={0,3,z};
        sort(tmp[i]+1,tmp[i]+4);
        ++cnt[tmp[i][1].j]; ans+=tmp[i][1].vl;
    }
}

ll b[N]; int tt;

inline void work () {
    int x=0;
    if (cnt[1]>n/2) x=1;
    else if (cnt[2]>n/2) x=2;
    else if (cnt[3]>n/2) x=3;
    if (!x) {printf ("%lld\n",ans); return ;}
    tt=0;
    for (int i=1;i<=n;++i) if (tmp[i][1].j==x) b[++tt]=tmp[i][2].vl-tmp[i][1].vl;
    sort(b+1,b+tt+1,[&](ll x,ll y){return x>y;});
    for (int i=1;i<=cnt[x]-n/2;++i) ans+=b[i];
    printf ("%lld\n",ans);
}

int main() {
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    int tes; in (tes); while (tes--) {
        init();
        work();
    }
    return 0;
}