#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
};
vector <edge> v[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    long long ans;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int uu,vv,ww;
        cin >> uu >> vv >> ww;
        v[uu].push_back({vv,ww});
        ans += ww;
    }
    cout << ans;
    return 0;
}
