#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
const int N=1e5+1;
int n;
struct node {
    int a, b, c;
    node() {}
    node(int a, int b, int c):a(a), b(b), c(c) {}
};
std::vector<node> a;
std::vector<int> d;
std::unordered_map<int, int> mp;
std::unordered_set<int> vis;
int b[N][3], c[3];
long long ans;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        a.clear(), mp.clear(), d.clear();
        c[0]=c[1]=c[2]=0;
        ans=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<3; j++) {
                int x;
                scanf("%d", &x);
                a.emplace_back(x, i, j);
                b[i][j]=x;
            }
            std::sort(b[i], b[i]+3, [](int a, int b) {
                return a>b;
            });
        }
        std::sort(a.begin(), a.end(), [](node a, node b) {
            return a.a>b.a;
        });
        for(node i:a) {
            if(mp.find(i.b)!=mp.end()) continue;
            c[i.c]++, ans+=i.a, mp[i.b]=i.c;
        }
        if(c[0]<=n>>1&&c[1]<=n>>1&&c[2]<=n>>1) printf("%lld\n", ans);
        else {
            int over=c[0]>n>>1?0:c[1]>n>>1?1:2, cnt=c[over]-(n>>1);
            vis.clear();
            for(node i:a) {
                if(mp[i.b]==over&&!vis.count(i.b)) d.emplace_back(b[i.b][0]-b[i.b][1]), vis.insert(i.b);
            }
            std::sort(d.begin(), d.end());
            for(int i=0; i<cnt; i++) {
                ans-=d[i];
            }
            printf("%lld\n", ans);
        }
    }

}