#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100002;

ll Get(ll x,ll y,ll z)
{
    if(x >= y && x >= z)
        return x - max(y,z);
    else if(y >= x && y >= z)
        return y - max(x,z);
    else
        return z - max(x,y);
}

struct Node
{
    ll x,y,z;

    bool operator< (const Node &t) const
    {
        return Get(x,y,z) < Get(t.x,t.y,t.z);
    }
};

ll ans;
int T,n;
Node a[MAXN];
vector <Node> vec[3];

void Clear()
{
    ans = 0;
    vec[0].clear(),vec[1].clear(),vec[2].clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> T;
    while(T--)
    {
        Clear();
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i].x >> a[i].y >> a[i].z;
        for(int i = 1;i <= n;i++)
        {
            ll x = a[i].x,y = a[i].y,z = a[i].z;
            ans += max(x,max(y,z));
            if(x >= y && x >= z)
                vec[0].push_back(a[i]);
            else if(y >= x && y >= z)
                vec[1].push_back(a[i]);
            else
                vec[2].push_back(a[i]);
        }

        if(vec[0].size() <= n / 2 && vec[1].size() <= n / 2 && vec[2].size() <= n / 2)
        {
            cout << ans << '\n';
            continue;
        }

        int id = 0;
        if(vec[0].size() > n / 2)
            id = 0;
        else if(vec[1].size() > n / 2)
            id = 1;
        else
            id = 2;
        
        sort(vec[id].begin(),vec[id].end());
        int len = vec[id].size() - n / 2;
        for(int i = 0;i < len;i++)
            ans -= Get(vec[id][i].x,vec[id][i].y,vec[id][i].z);
        cout << ans << '\n';
    }

    return 0;
}