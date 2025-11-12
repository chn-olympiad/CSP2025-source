#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
struct node{
    int u;
    int v;
    int w;
};
node road[N];
bool cmp(node a,node b){
    return a.w<b.w;
}
int n,m,k,cost=0;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>road[i].u>>road[i].v>>road[i].w;
    }
    sort(road+1,road+n+1,cmp);
    for(int i=1;i<n;i++){
        cost+=road[i].w;
    }
    cout<<cost;
    return 0;
}
