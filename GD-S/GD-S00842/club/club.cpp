#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define ROF(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define int long long
using namespace std;
const int N = 1e5+5;
int suf[N];
struct node { int x,y,z; } a[N];
struct node2 { 
    int x,y,del; 
    bool operator < (const node2 &y) const {
        return del > y.del;
    }    
};
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        priority_queue<node2> q1,q2;
        FOR(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z;
        sort(a+1,a+n+1,[](node xx,node yy) { return max(xx.x,xx.y)-xx.z > max(yy.x,yy.y)-yy.z; });
        suf[n+1] = 0;
        ROF(i,n,1) suf[i] = suf[i+1]+a[i].z;
        int pre = 0, ans = 0;
        FOR(i,1,n) {
            if(a[i].x == a[i].y) {
                if(q1.size() < n/2) q1.push({a[i].x,a[i].y,0});
                else q2.push({a[i].x,a[i].y,0});
                pre += a[i].x;
            } else if(a[i].x > a[i].y) {
                int del = a[i].x-a[i].y;
                if(q1.size() < n/2) q1.push({a[i].x, a[i].y, del}), pre+=a[i].x;
                else {
                    auto tmp = q1.top();
                    if(tmp.del >= del) q2.push({a[i].x, a[i].y, -del}), pre+=a[i].y;
                    else {
                        q1.pop(); pre -= tmp.x;
                        q1.push({a[i].x, a[i].y, del}); pre += a[i].x;
                        q2.push({tmp.x, tmp.y, -tmp.del}); pre += tmp.y;
                    }
                }
            } else if(a[i].y > a[i].x) {
                int del = a[i].y-a[i].x;
                if(q2.size() < n/2) q2.push({a[i].x, a[i].y, del}), pre+=a[i].y;
                else {
                    auto tmp = q2.top();
                    if(tmp.del >= del) q1.push({a[i].x, a[i].y, -del}), pre+=a[i].x;
                    else {
                        q2.pop(); pre -= tmp.y;
                        q2.push({a[i].x, a[i].y, del}); pre += a[i].y;
                        q1.push({tmp.x, tmp.y, -tmp.del}); pre += tmp.x;
                    }
                }

            }
            if(i >= n/2) ans = max(ans, pre+suf[i+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
