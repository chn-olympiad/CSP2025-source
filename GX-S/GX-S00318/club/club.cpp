#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define qwq Ff472130
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
const int N=2e5+10;
const int inf=1e9+7;

inline void read(int &x) {
    x=0;
    char ch=getchar();
    while (ch<48) ch=getchar();
    while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int n;
int a[N][3];
vector<int> tmp[10];

inline void work(int id,ll &ans) {
    sort(tmp[id].begin(),tmp[id].end());
    int siz=tmp[id].size()-n/2-1;
    f(i,0,siz) ans-=tmp[id][i];
}

inline void solve() {
    ll ans=0;
    read(n);
    f(i,1,n) {
        f(j,0,2) read(a[i][j]);
        int mx=max(a[i][0],max(a[i][1],a[i][2]));
        if (a[i][0]==mx) tmp[0].push_back(mx-max(a[i][1],a[i][2]));
        else if (a[i][1]==mx) tmp[1].push_back(mx-max(a[i][0],a[i][2]));
        else tmp[2].push_back(mx-max(a[i][0],a[i][1]));
        ans+=mx;
    }
    if (tmp[0].size()>n/2) work(0,ans);
    if (tmp[1].size()>n/2) work(1,ans);
    if (tmp[2].size()>n/2) work(2,ans);
    printf("%lld\n",ans);
    tmp[0].clear();
    tmp[1].clear();
    tmp[2].clear();
}


int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    read(T);
    while (T--) solve();
    return 0;
}
