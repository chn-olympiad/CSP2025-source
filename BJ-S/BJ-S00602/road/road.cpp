#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
vector <edge> v[100005];
edge e[1000005];
int connect[100005];
bool cmp(edge x,edge y){
    return x.w > y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    long long ans=0;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int uu,vv,ww;
        cin >> uu >> vv >> ww;
        v[uu].push_back({vv,ww});
        e[i].v = vv;
        e[i].u = uu;
        e[i].w = ww;
        connect[uu]++;
        connect[vv]++;
        ans += ww;
    }
    sort(e+1,e+m+1,cmp);
    for(int i = 1;i <= m;i++){
        if(connect[e[i].u]-1>0&&connect[e[i].v]-1>0){
            ans -= e[i].w;
            connect[e[i].u]--;
            connect[e[i].v]--;
        }
    }
    cout << ans;
    return 0;
}
