#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

// void srt(int a1, int a2, int a3)
// {
//     if(a1 >= a2 && a2 >= a3) zd.push_back(1), zdval.push_back(a1), cd.push_back(2), cdval.push_back(a2);
//     else if(a1 >= a3 && a3 >= a2) zd.push_back(1), zdval.push_back(a1), cd.push_back(3), cdval.push_back(a3);
//     else if(a2 >= a1 && a1 >= a3) zd.push_back(2), zdval.push_back(a2), cd.push_back(1), cdval.push_back(a1);
//     else if(a2 >= a3 && a3 >= a1) zd.push_back(2), zdval.push_back(a2), cd.push_back(3), cdval.push_back(a3);
//     else if(a3 >= a1 && a1 >= a2) zd.push_back(3), zdval.push_back(a3), cd.push_back(1), cdval.push_back(a1);
//     else if(a3 >= a2 && a2 >= a1) zd.push_back(3), zdval.push_back(a3), cd.push_back(2), cdval.push_back(a2);
// }

struct Edge {int v, val;};
int zdval[MAX], cdval[MAX];
bool comp(Edge a, Edge b) {return a.val - cdval[a.v] > b.val - cdval[b.v];}
void solve()
{
    vector<Edge> zd[5], cd[5];

    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        if(a1 >= a2 && a2 >= a3) zd[1].push_back({i, a1}), zdval[i] = a1, cd[2].push_back({i, a2}), cdval[i] = a2;
        else if(a1 >= a3 && a3 >= a2) zd[1].push_back({i, a1}), zdval[i] = a1, cd[3].push_back({i, a3}), cdval[i] = a3;
        else if(a2 >= a1 && a1 >= a3) zd[2].push_back({i, a2}), zdval[i] = a2, cd[1].push_back({i, a1}), cdval[i] = a1;
        else if(a2 >= a3 && a3 >= a1) zd[2].push_back({i, a2}), zdval[i] = a2, cd[3].push_back({i, a3}), cdval[i] = a3;
        else if(a3 >= a1 && a1 >= a2) zd[3].push_back({i, a3}), zdval[i] = a3, cd[1].push_back({i, a1}), cdval[i] = a1;
        else if(a3 >= a2 && a2 >= a1) zd[3].push_back({i, a3}), zdval[i] = a3, cd[2].push_back({i, a2}), cdval[i] = a2;
    }
    long long ans = 0;
    for(int i=1; i<=3; i++)
    {

        int sz = zd[i].size();
        if(sz > n/2)
        {
            sort(zd[i].begin(), zd[i].end(), comp);
            // for(auto x : zd[i])
            //     cout << i << ' ' << x.v << ' ' << x.val << endl;
            int j=0; for(auto t : zd[i])
            {
                ++j;
                if(j <= n/2) ans += t.val;
                else ans += cdval[t.v];
            }
        }
        else
            for(auto t : zd[i])
                ans += t.val;
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T; cin >> T;
    while(T--) solve();

    return 0;
}
