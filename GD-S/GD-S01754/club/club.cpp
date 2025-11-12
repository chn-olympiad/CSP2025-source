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

const int N=100005;

int T,n,cur,ans;
pii a[N][4];
vector<int> vec[4];

bool cmp(const pii& a,const pii& b) {
    return a.first>b.first;
}

bool cmpp(const int& i,const int& j) {
    int deci,decj;
    _rep(t,1,2) if (a[i][t].second==cur) deci=a[i][t].first-a[i][t+1].first;
    _rep(t,1,2) if (a[j][t].second==cur) decj=a[j][t].first-a[j][t+1].first;
    return deci>decj;
}

int main() {
    FRR("club.in");
    FRW("club.out");
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        _rep(j,1,3) vec[j].clear();
        ans=0;
        _rep(i,1,n) _rep(j,1,3) scanf("%d",&(a[i][j].first)),a[i][j].second=j;
        _rep(i,1,n) sort(a[i]+1,a[i]+4,cmp);
        _rep(i,1,n) vec[a[i][1].second].emplace_back(i),ans+=a[i][1].first;
        while (true) {
            if (vec[1].size()<=n/2 && vec[2].size()<=n/2 && vec[3].size()<=n/2) break;
            if (vec[1].size()>n/2) cur=1;
            else if (vec[2].size()>n/2) cur=2;
            else cur=3;
            sort(vec[cur].begin(),vec[cur].end(),cmpp);
            while (vec[cur].size()>n/2) {
                int k=vec[cur].back(); vec[cur].pop_back();
                int dec,nex;
                _rep(t,1,2) if (a[k][t].second==cur) dec=a[k][t].first-a[k][t+1].first,nex=a[k][t+1].second;
                ans-=dec;
                vec[nex].emplace_back(cur);
            }
        }
        printf("%d\n",ans);
    }
    // TIMESTAMP
    return 0;
}

// 14:49