#include<bits/stdc++.h>
using namespace std;

const int nr = 1e5 + 10;
int n; vector<int> vec[3];
struct node
{
    int data[3];
    friend bool operator < (const node x, const node y)
    {
        return max({x.data[0], x.data[1], x.data[2]}) > max({y.data[0], y.data[1], y.data[2]});
    }
} a[nr];

bool cmp(int x, int y)
{
    return a[x].data[2] - a[x].data[1] < a[y].data[2] - a[y].data[1];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        vec[0].clear(), vec[1].clear(), vec[2].clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 2; j++)
                cin >> a[i].data[j];
        sort(a + 1, a + n + 1);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int mxid = 0;
            if (max({a[i].data[0], a[i].data[1], a[i].data[2]}) == a[i].data[0]) mxid = 0;
            else if (max({a[i].data[0], a[i].data[1], a[i].data[2]}) == a[i].data[1]) mxid = 1;
            else mxid = 2;
            res += a[i].data[mxid], vec[mxid].push_back(i);
        }
        for (int i = 1; i <= n; i++) sort(a[i].data, a[i].data + 3);
        if (vec[0].size() > n / 2)
        {
            sort(vec[0].begin(), vec[0].end(), cmp);
            for (int i = 0; i < vec[0].size() - n / 2; i++) res += (a[vec[0][i]].data[1] - a[vec[0][i]].data[2]);
        }
        else if (vec[1].size() > n / 2)
        {
            sort(vec[1].begin(), vec[1].end(), cmp);
            for (int i = 0; i < vec[1].size() - n / 2; i++) res += (a[vec[1][i]].data[1] - a[vec[1][i]].data[2]);
        }
        else if (vec[2].size() > n / 2)
        {
            sort(vec[2].begin(), vec[2].end(), cmp);
            for (int i = 0; i < vec[2].size() - n / 2; i++) res += (a[vec[2][i]].data[1] - a[vec[2][i]].data[2]);
        }
        cout << res << '\n';
    }
    return 0;
}
