#include <bits/stdc++.h>
using namespace std;

const int N=1e5+6;
int n,sum[4];
struct node {
    int x,y,z;
    bool operator<(const node& a) const {return x<a.x;}
}a[N];

namespace A {
    int solve() {
        int res=0;
        sort(a+1,a+n+1,[](node aa,node bb) {return aa.x>bb.x;});
        for (int i=1;i<=n/2;i++) res+=a[i].x;
        return res;
    }
}

namespace B {
    int solve() {
        int res=0;
        sort(a+1,a+n+1,[](node aa,node bb) {return aa.x-aa.y>bb.x-bb.y;});
        for (int i=1;i<=n/2;i++) res+=a[i].x;
        for (int i=1+n/2;i<=n;i++) res+=a[i].y;
        return res;
    }
}

namespace violence {
    int cnt[4],b[12],ans;
    void init() {
        memset(cnt,0,sizeof(cnt));
        memset(b,0,sizeof(b));
        ans=0;
    }
    void dfs(int d) {
        if (d==n+1) {
            int res=0;
            for (int i=1;i<=n;i++) {
                if (b[i]==1) res+=a[i].x;
                else if (b[i]==2) res+=a[i].y;
                else res+=a[i].z;
            }
            ans=max(ans,res);
            return;
        }
        for (int i=1;i<=3;i++) {
            if (cnt[i]<n/2) {
                cnt[i]++;
                b[d]=i;
                dfs(d+1);
                cnt[i]--;
                b[d]=0;
            }
        }
    }
    int solve() {
        init();
        dfs(1);
        return ans;
    }
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T; cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i].x>>a[i].y>>a[i].z;
            sum[1]+=a[i].x,sum[2]+=a[i].y,sum[3]+=a[i].z;
        }
        if (sum[2]==0&&sum[3]==0) {
            using namespace A;
            cout<<solve()<<'\n';
        } else if (sum[3]==0) {
            using namespace B;
            cout<<solve()<<'\n';
        } else {
            using namespace violence;
            cout<<solve()<<'\n';
        }
    }
    return 0;
}
