#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int n;
ll k,a[N],sum[N],m;
struct edge{
    int u,v;
};
vector<edge> segs;
int p;
ll ans;
//x ^ 0 = x

bool cmp(edge a,edge b){
    if(a.v != b.v) return a.v < b.v;
    return a.u < b.u;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i = 1;i <= n;++ i){
        scanf("%lld",&a[i]);
        sum[i] = (sum[i - 1] ^ a[i]);
    }
    //O(n ^ 2) -> 60pts
    for(int i = 1;i <= n;++ i){
        for(int j = i;j <= n;++ j){
            if((sum[j] ^ sum[i - 1]) == k){
                segs.push_back({i,j});
            }
        }
    }
    m = segs.size();
    sort(segs.begin(),segs.end(),cmp);
    for(edge x : segs){
        int l = x.u,r = x.v;
        if(l > p){
            ++ ans;
            p = r;
        }
    }
    printf("%lld",ans);
    return 0;
}