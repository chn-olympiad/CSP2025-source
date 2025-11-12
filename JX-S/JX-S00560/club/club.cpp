#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    ll x,y,z;
}a[100100];
bool cmp(Node u,Node v){
    ll ua=max({u.x,u.y,u.z});
    ll uc=min({u.x,u.y,u.z});
    ll ub=u.x+u.y+u.z-ua-uc;
    ll va=max({v.x,v.y,v.z});
    ll vc=min({v.x,v.y,v.z});
    ll vb=v.x+v.y+v.z-va-vc;
    if ((ua-ub)==(va-vb)) return (ub-uc)>(vb-vc);
    return (ua-ub)>(va-vb);
}
vector<pair<int,int>> tmp;
int vis[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int Tcs;
    scanf("%d",&Tcs);
    while (Tcs--){
        int n;
        scanf("%d",&n);
        vis[1]=vis[2]=vis[3]=n/2;
        for (int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
        }
        sort(a+1,a+n+1,cmp);
        ll ans=0;
        for (int i=1;i<=n;i++){
            tmp.clear();
            tmp.push_back({a[i].x,1});
            tmp.push_back({a[i].y,2});
            tmp.push_back({a[i].z,3});
            sort(tmp.begin(),tmp.end());
            for (int j=2;j>=0;j--){
                if (vis[tmp[j].second]==0) continue;
                vis[tmp[j].second]--;
                ans += tmp[j].first;
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
