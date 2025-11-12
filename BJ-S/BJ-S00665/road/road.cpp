#include "bits/stdc++.h"
using namespace std;
//#define int long long
int ans;
const int N = 1e6+100,M = 1e4+100;
int n,m,k;
int F[M],cnt1[M],cnt2[M];
int Find(int x)
{
    return (F[x] == x?x:F[x] = Find(F[x]));
}
struct Node
{
    int u,v,w;
};
vector<Node> mp;
int c[20][M];
bool cmp(Node a,Node b)
{
    return a.w < b.w;
}
signed main()
{
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        F[i] = i;
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        mp.push_back({u,v,w});
    }
    sort(mp.begin(),mp.end(),cmp);
    //for(int i = 0;i < m;i++)
      //  cout << mp[i].u << ' ' << mp[i].v << ' ' << mp[i].w << "\n";
    for(int i =1;i <= k;i++)
    {
        for(int j = 0;j <= n;j++)
            cin >> c[i][j];
    }
    for(int i = 0;i < m;i++)
    {
        if(Find(mp[i].u) != Find(mp[i].v))
        {
            bool f = 1;

            for(int j = 1;j <= k;j++)
            {
                if(c[j][mp[i].u]+c[j][mp[i].v] <= mp[i].w)
                {
                    cnt1[j] += c[j][mp[i].u]+c[j][mp[i].v]+c[j][0];
                    c[j][mp[i].u] = 0;
                    c[j][mp[i].v] = 0;
                    c[j][0] = 0;
                    cnt2[j] += mp[i].w;
                    for(int q = 1;q <= n;q++)
                    {
                        if(Find(q) == Find(mp[i].u) || Find(q) == Find(mp[i].v))
                            c[j][q] = 0;
                    }
                    F[mp[i].u] = Find(mp[i].v);
                    f = 0;
                    break;
                }
            }
            if(f)
            {

                ans += mp[i].w;
                F[mp[i].v] = Find(mp[i].u);
                //cout << mp[i].u << ' ' << mp[i].v << "\n";
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        ans += min(cnt1[i],cnt2[i]);
        //if(cnt1[i] < cnt2[i])
            //cout << i << ' ';
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
