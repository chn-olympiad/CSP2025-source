#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
int fa[10218];
int townmp[11][10218];
struct edge{
    int side1,side2,val;
};
struct cmp{
    bool operator()(edge e1,edge e2){
        return e1.val>e2.val;
    }
};
priority_queue<edge,vector<edge>,cmp> p;
ll quickread(){
    char c = getchar();
    while(!isdigit(c)){c = getchar();}
    ll ans = 0;
    while(isdigit(c)){
        ans = ans*10+c-'0';
        c = getchar();
    }
    return ans;
}
int findfa(int cur){
    if(fa[cur] == cur)return cur;
    int last = fa[cur];
    fa[cur] = findfa(last);
    return fa[cur];
}
ll buildtree(){
    ll ans = 0;
    int alr = 0;
    while(alr<n-1){
        edge cur = p.top();
        p.pop();
        if(findfa[cur.side1]==findfa[cur.side2])continue;
        ans+=cur.val;
        fa[findfa(cur.side1)] = fa[findfa(cur.side2)];
        alr++;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = quickread(),m = quickread(),k = quickread();
    for(int i = 1,s1,s2,v;i<=n;++i){
        s1 = quickread(),s2 = quickread(),v = quickread();
        p.push((edge){s1,s2,v});
    }
    for(int i = 1;i<=k;++i){
        townmp[i][0] = quickread();
        for(int j = 1;j<=n;++j){
            townmp[i][j] = quickread();
        }
    }
    ll ans = buildtree();
    if(k == 0){
        printf("%lld",ans);
    }
}
