#include <bits/stdc++.h>
#define ll long long
const int maxn=2e5+5;
using namespace std;
int t,n,p[6];
ll ans;
struct St {
    ll m1,m2,m3,maxp,maxm;
    int maxx;
}st[maxn];
bool cmp(St s1,St s2) {
    return s1.maxm>s2.maxm;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld %lld %lld",&st[i].m1,&st[i].m2,&st[i].m3);
            if (max(st[i].m1,max(st[i].m2,st[i].m3))==st[i].m1)
                st[i].maxp=st[i].m1,st[i].maxx=1,st[i].maxm=st[i].m1-max(st[i].m2,st[i].m3);
            else if (max(st[i].m1,max(st[i].m2,st[i].m3))==st[i].m2)
                st[i].maxp=st[i].m2,st[i].maxx=2,st[i].maxm=st[i].m2-max(st[i].m1,st[i].m3);
            else
                st[i].maxp=st[i].m3,st[i].maxx=3,st[i].maxm=st[i].m3-max(st[i].m1,st[i].m2);
        }
        sort(st+1,st+n+1,cmp);
        int pp=n/2;
        ans=p[1]=p[2]=p[3]=0;
        for (int i=1;i<=n;i++) {
            //cout<<st[i].maxm<<"\n";
            if (p[st[i].maxx]<pp)
                ans+=st[i].maxp,p[st[i].maxx]+=1;
            else
                ans+=st[i].maxp-st[i].maxm;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
