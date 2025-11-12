#include <bits/stdc++.h>
using namespace std;
using ill = long long;
const int N = 1e5+5;
int n;
ill ans;
struct Node{
    ill d[3];
    ill dis(int x,int y) const{
        return d[x] - d[y];
    }
}a[N];
vector<int> f[3];
bool cmp0(int x,int y){
    return min(a[x].dis(0,1),a[x].dis(0,2)) > min(a[y].dis(0,1),a[y].dis(0,2));
}
bool cmp1(int x,int y){
    return min(a[x].dis(1,0),a[x].dis(1,2)) > min(a[y].dis(1,0),a[y].dis(1,2));
}
bool cmp2(int x,int y){
    return min(a[x].dis(2,0),a[x].dis(2,1)) > min(a[y].dis(2,0),a[y].dis(2,1));
}
void init(){
    ans = 0ll;
    memset(a,0,sizeof(a));
    f[0].clear();
    f[1].clear();
    f[2].clear();
}
void solve(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i].d[0],&a[i].d[1],&a[i].d[2]);
    for(int i=1;i<=n;i++){
        Node q = a[i];
        ill maxn = max(q.d[0],max(q.d[1],q.d[2]));
        if(maxn == q.d[0])
            f[0].push_back(i);
        else if(maxn == q.d[1])
            f[1].push_back(i);
        else
            f[2].push_back(i);
    }
    if(f[0].size() > (n >> 1)){
        sort(f[0].begin(),f[0].end(),cmp0);
        while(f[0].size() > (n >> 1)){
            int q = f[0][f[0].size()-1];
            f[0].pop_back();
            if(a[q].d[1] > a[q].d[2])
                f[1].push_back(q);
            else
                f[2].push_back(q);
        }
    }else if(f[1].size() > (n >> 1)){
        sort(f[1].begin(),f[1].end(),cmp1);
        while(f[1].size() > (n >> 1)){
            int q = f[1][f[1].size()-1];
            f[1].pop_back();
            if(a[q].d[0] > a[q].d[2])
                f[0].push_back(q);
            else
                f[2].push_back(q);
        }
    }else if(f[2].size() > (n >> 1)){
        sort(f[2].begin(),f[2].end(),cmp2);
        while(f[2].size() > (n >> 1)){
            int q = f[2][f[2].size()-1];
            f[2].pop_back();
            if(a[q].d[0] > a[q].d[1])
                f[0].push_back(q);
            else
                f[1].push_back(q);
        }
    }
    for(int i=0;i<=2;i++)
        for(auto j:f[i])
            ans += a[j].d[i];
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
